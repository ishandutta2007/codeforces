#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 1e6 + 100;
int a[N], b[N];
int n, m;
ll cnt_inv(){
    vector <int> sorted(a, a + n);
    sort(sorted.begin(), sorted.end());
    vector <int> fenv(n + 1);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        int p = lower_bound(sorted.begin(), sorted.end(), a[i]) - sorted.begin();
        int x = p;
        ans += i;
        while(x >= 0){
            ans -= fenv[x];
            x = (x & (x + 1)) - 1;
        }
        x = p;
        while(x <= n){
            fenv[x]++;
            x = x | (x + 1);
        }
    }
    return ans;
}
ll Tree1[4 * N], Tree2[4 * N];
void build(int v, int l, int r){
    if(l == r){
        Tree1[v] = l;
        return;
    }
    build(v * 2, l, (r + l) / 2);
    build(v * 2 + 1, (r + l) / 2 + 1, r);
    Tree1[v] = min(Tree1[v * 2], Tree1[v * 2 + 1]);
}

void push(int v, int l, int r){
    Tree1[v * 2] += Tree2[v];
    Tree2[v * 2] += Tree2[v];
    Tree1[v * 2 + 1] += Tree2[v];
    Tree2[v * 2 + 1] += Tree2[v];
    Tree2[v] = 0;
}

void add(int v, int l, int r, int al, int ar, ll x){
    if(l >= al && r <= ar){
        Tree2[v] += x;
        Tree1[v] += x;
        return;
    }
    if(r < al || ar < l){
        return;
    }
    push(v, l, r);
    add(v * 2, l, (r + l) / 2, al, ar, x);
    add(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
    Tree1[v] = min(Tree1[v * 2], Tree1[v * 2 + 1]);
}
ll query(int v, int l, int r, int al, int ar){
    if(l >= al && r <= ar){
        return Tree1[v];
    }
    if(l > ar || al > r){
        return 1e9;
    }
    push(v, l, r);
    return min(query(v * 2, l, (r + l) / 2, al, ar), query(v * 2 + 1, (r + l) / 2 + 1, r, al, ar));
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector <pair <int, int> > pos(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[i] = {a[i], i};
        }
        sort(pos.begin(), pos.end());
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        sort(b, b + m);
        ll ans = cnt_inv();
        fill(Tree1, Tree1 + 4 * (n + 4), 0);
        fill(Tree2, Tree2 + 4 * (n + 4), 0);
        build(1, 0, n);
        int cur1 = 0, cur2 = 0;
        for(int i = 0; i < m; i++){
            int r = b[i];
            while(cur1 < n && pos[cur1].X < r){
                int s = pos[cur1].Y;
                add(1, 0, n, 0, s, 1);
                cur1++;
            }
            while(cur2 < n && pos[cur2].X <= r){
                int s = pos[cur2].Y;
                add(1, 0, n, s + 1, n, -1);
                cur2++;
            }
            ans += Tree1[1];
        }
        cout << ans << "\n";
    }
    return 0;
}