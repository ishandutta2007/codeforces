#include<bits/stdc++.h>
using namespace std;

#define sz(a) (int)a.size()
#define X first
#define Y second
const int N = 2e5 + 100;
const int mod = 1e9 + 7;

int Tree[4 * N];

int get(int v, int l, int r, int idx){
    if(l == r){
        return Tree[v];
    }
    int m = (r + l) / 2;
    if(idx <= m){
        int ans = Tree[v] + get(v * 2, l, m, idx);
        if(ans >= mod){
            ans -= mod;
        }
        return ans;
    }
    else{
        int ans = Tree[v] + get(v * 2 + 1, m + 1, r, idx);
        if(ans >= mod){
            ans -= mod;
        }
        return ans;
    }
}

void update(int v, int l, int r, int al, int ar, int x){
    if(al > ar){
        return;
    }
    if(l >= al && r <= ar){
        Tree[v] += x;
        if(Tree[v] >= mod){
            Tree[v] -= mod;
        }
    }
    else if(l <= ar && r >= al){
        update(v * 2, l, (r + l) / 2, al, ar, x);
        update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, x);
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    vector <bool> used(n);
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        x--;
        used[x] = 1;
    }
    vector <pair <int, int> > vec;
    vector <pair <int, int> > mass_b;
    for(int i = 0; i < n; i++){
        vec.push_back({a[i], b[i]});
        mass_b.push_back({b[i], i});
    }
    sort(mass_b.begin(), mass_b.end());
    int lst = 0;
    vector <vector <int> > queries(n);
    sort(vec.begin(), vec.end());
    for(int i = sz(mass_b) - 1; i >= 0; i--){
        if(used[mass_b[i].Y] && mass_b[i].X > lst && a[mass_b[i].Y] > lst){
            int val = a[mass_b[i].Y];
            int idx_val = lower_bound(vec.begin(), vec.end(), make_pair(lst, 0)) - vec.begin();
  //          cout << lst << " ";
            lst = val;
    //        cout << mass_b[i].Y << " " << a[mass_b[i].Y] << " " << mass_b[i].X << "\n";
            queries[idx_val].push_back(i);
        }
    }
    int ans = 0;
    for(int i = sz(vec) - 1; i >= 0; i--){
        int idx = lower_bound(mass_b.begin(), mass_b.end(), make_pair(vec[i].Y, 0)) - mass_b.begin();
        update(1, 0, n - 1, idx, idx, 1);
        update(1, 0, n - 1, idx + 1, n - 1, get(1, 0, n - 1, idx));
        for(auto query : queries[i]){
            ans = (ans + get(1, 0, n - 1, query)) % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}