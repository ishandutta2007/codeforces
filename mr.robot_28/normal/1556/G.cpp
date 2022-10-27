#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 1e9 + 7;
ll a[N], b[N];
set <pair <pair <ll, ll>, int> > add1;
set <pair <pair <ll, ll>, int> > have;
struct node{
    int to[2];
    int len;
    ll l, r;
    ll mask;
    int zest, stop;
    node(){
        to[0] = to[1] = -1;
        zest = stop = len = 0;
        mask = 0;
    }
} tree[N * 20];
int dsu[N * 20], rang[N * 20];
int get(int v){
    if(v == dsu[v]){
        return v;
    }
    return dsu[v] = get(dsu[v]);
}
void unite(int a, int b){

  // cout << "A " << a << " " << b << "\n";
    //cout << tree[a].l << " " << tree[a].r << " " << tree[b].l << " " << tree[b].r << "\n";
    a = get(a);
    b = get(b);
    if(a != b){
        if(rang[a] < rang[b]){
            swap(a, b);
        }
        dsu[b] = a;
        rang[a] += rang[b];
    }
}
int it = 1;
void add(int v, ll l, ll r, ll al, ll ar, int len = 0, ll mask = 0){
    
    tree[v].l = l;
    tree[v].r = r;
    if(al > ar){
        return;
    }
    if(ar < l || al > r){
        return;
    }
    tree[v].mask = mask;
    tree[v].len = len;
    tree[v].stop = 0;
    if(l >= al && r <= ar){
        tree[v].stop = 1;
        tree[v].zest = 1;
        add1.insert({{l, r}, v});
    }
    else{
        int m = (r + l) / 2;
        if(al <= m){
            if(tree[v].to[0] == -1){
                tree[v].to[0] = it++;
                tree[tree[v].to[0]].to[0] = -1;
                tree[tree[v].to[0]].to[1] = -1;
            }
            add(tree[v].to[0], l, m, al, ar, len + 1, mask);
        }
        if(ar > m){
            if(tree[v].to[1] == -1){
                tree[v].to[1] = it++;
                tree[tree[v].to[1]].to[0] = -1;
                tree[tree[v].to[1]].to[1] = -1;
            }
            add(tree[v].to[1], m + 1, r, al, ar, len + 1, mask ^ (1ll << len));
        }
    }
}
void funct(int v){
    if(tree[v].stop)
    {
        return;
    }
    tree[v].stop = 1;
    for(int j = 0; j < 2; j++){
        if(tree[v].to[j] != -1){
            unite(v, tree[v].to[j]);
            funct(tree[v].to[j]);
        }
    }
}
void go(int root){
    ll mask = tree[root].mask;
    int len = tree[root].len;
    int v = 0;
//   cout << root << " " << mask << " " << tree[root].l << " " << tree[root].r << "\n";
    for(int i = 0; i < len; i++){
        int go = (mask >> i) & 1;
        if(tree[v].to[go ^ 1] != -1){
            int cp = tree[v].to[go ^ 1];
            if(tree[cp].zest){
                unite(root, cp);
                break;
            }
            else{
                int need = 1;
                for(int j = i + 1; j < len; j++){
                    int goo = (mask >> j) & 1;
                    if(tree[cp].to[goo] == -1){
                        need = 0;
                        break;
                    }
                    cp = tree[cp].to[goo];
                    if(tree[cp].zest){
                      //  cout << "E " << tree[cp].l << " " << tree[cp].r << " " << tree[root].l << " " << tree[root].r << "\n";
                        unite(root, cp);
                        need = 0;
                        break;
                    }
                }
                if(need){
             //       cout << i << " " << tree[v].l << " " << tree[v].r << " " << tree[cp1].l << " " << tree[cp1].r << " ";
               //     cout << "E " << len << "\n";
                    unite(root, cp);
                    funct(cp);
                }
            }
        }
        if(tree[v].to[go] == -1){
            return;
        }
        v = tree[v].to[go];
        if(tree[v].zest){
            unite(root, v);
            return;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < N * 20; i++){
        dsu[i] = i;
        rang[i] = 1;
        tree[i] = node();
    }
    vector <ll> vec;
    vector <string> s(m);
    for(int i = 0; i < m; i++){
        cin >> s[i];
        cin >> a[i] >> b[i];
        if(s[i] == "block"){
            vec.push_back(a[i]);
            vec.push_back(b[i]);
        }
    }
    sort(vec.begin(), vec.end());
    if(sz(vec) == 0){
        add(0, 0, (1ll << n) - 1, 0, (1ll << n) - 1);
    }
    else{
        add(0, 0, (1ll << n) - 1, 0, vec[0] - 1);
        for(int i = 1; i + 1 < sz(vec); i += 2){
            add(0, 0, (1ll << n) - 1, vec[i] + 1, vec[i + 1] - 1);
        }
        add(0, 0, (1ll << n) - 1, vec[vec.size() - 1] + 1, (1ll << n) - 1);
    }
    for(auto c : add1){
        go(c.Y);
        have.insert({{c.X.Y, c.X.X}, c.Y});
    }
    add1.clear();
    vector <int> res;
   // cout << "K\n";
    for(int i = m - 1; i >= 0; i--){
        ll vl = a[i];
        ll vr = b[i];
        if(s[i] == "ask"){
            int v1 = have.lower_bound({{vl, -1}, -1}) -> Y;
            int v2 = have.lower_bound({{vr, -1}, -1}) -> Y;
            res.push_back(get(v1) == get(v2));
        }
        else{
            add(0, 0, (1ll << n) - 1, vl, vr);
            for(auto c : add1){
                go(c.Y);
                have.insert({{c.X.Y, c.X.X}, c.Y});
            }
            add1.clear();
        }
    }
    reverse(res.begin(), res.end());
    for(auto x : res)
    {
        cout << x << "\n";
    }
    return 0;
}