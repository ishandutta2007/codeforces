#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
int Tree[N];
vector <int> Tree1[N];
void update(int x, int val){
    while(x < N){
        Tree[x] += val;
        x = x | (x + 1);
    }
}
int q1(int x){
    int res = 0;
    while(x >= 0){
        res += Tree[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}
void update1(int id, int x, int val){
    while(x < sz(Tree1[id])){
        Tree1[id][x] += val;
        x = x | (x + 1);
    }
}
int q2(int id, int x){
    int res = 0;
    while(x >= 0){
        res += Tree1[id][x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}
vector <vector <int> > vec;
map <vector <int>, int> mp1;
map <vector <int>, int> mp2;
vector <pair <int, int> > vec1[N];
map <pair <int, int>, int> mp;
ll funct1(int u, int v){
    int l = 0, r = 2e9 + 1;
    int w = mp[{u, v}];
    while(r - l > 1){
        int midd = (r + l) / 2;
        int l1 = -1, r1 = sz(vec);
        while(r1 - l1 > 1){
            int midd1 = (r1 + l1) / 2;
            if(vec[midd1][2] <= midd){
                l1 = midd1;
            }
            else{
                r1 = midd1;
            }
        }
        int l2 = -1, r2 = sz(vec1[u]);
        while(r2 - l2 > 1){
            int midd2 = (r2 + l2) / 2;
            if(vec1[u][midd2].Y <= midd){
                l2 = midd2;
            }
            else{
                r2 = midd2;
            }
        }
        int l3 = -1, r3 = sz(vec1[v]);
        while(r3 - l3 > 1){
            int midd3 = (l3 + r3) / 2;
            if(vec1[v][midd3].Y <= midd){
                l3 = midd3;
            }
            else{
                r3 = midd3;
            }
        }
        int val1 = q1(l1);
        int val2 = q2(u, l2) + q2(v, l3);
        if(w <= midd){
            val2--;
        }
        if(val1 > val2){
            r = midd;
        }
        else{
            l = midd;
        }
    }
    return 1LL * w + r;
}
ll funct2(int v){
    
   // cout << "A " << v << "\n";
    if(q2(v, sz(Tree1[v]) - 1) == 2){
        return 2e9;
    }
    int l1 = -1, r1 = sz(Tree1[v]);
    while(r1 - l1 > 1){
        int midd = (r1 + l1) / 2;
        if(q2(v, midd) >= 1){
            r1 = midd;
        }
        else{
            l1 = midd;
        }
    }
    int l2 = -1, r2 = sz(Tree1[v]);
    while(r2 - l2 > 1){
        int midd = (l2 + r2) / 2;
        if(q2(v, midd) >= 2){
            r2 = midd;
        }
        else{
            l2 = midd;
        }
    }
    int l3 = -1, r3 = sz(Tree1[v]);
    while(r3 - l3 > 1){
        int midd = (l3 + r3) / 2;
        if(q2(v, midd) >= 3){
            r3 = midd;
        }
        else{
            l3 = midd;
        }
    }
    return 1LL * vec1[v][r1].Y + vec1[v][r2].Y + vec1[v][r3].Y;
}
ll funct(){
    int l = -1, r = sz(vec);
    while(r - l > 1)
    {
        int midd = (r + l) / 2;
        if(q1(midd) >= 1){
            r = midd;
        }
        else{
            l = midd;
        }
    }
    int l1 = -1, r1 = sz(vec);
    while(r1 - l1 > 1){
        int midd = (r1 + l1) / 2;
        if(q1(midd) >= 2){
            r1 = midd;
        }
        else{
            l1 = midd;
        }
    }
    int a = vec[r][0];
    int b = vec[r][1];
    int c = vec[r1][0];
    int d = vec[r1][1];
//    cout << r << " " << r1 << "\n";
  //  cout << q1(r) << " " << q1(r1) << "\n"; 
    //cout << a << " " << b << " "  << c << " " << d << "\n";
    if(a != c && a != d && b != c && b != d){
        return vec[r][2] + vec[r1][2];
    }
    ll val = min(funct1(a, b), funct1(c, d));
    if(a == c || a == d){
        val = min(val, funct2(a));
    }
    if(b == c || b == d){
        val = min(val, funct2(b));
    }
    if(a == c && mp[{b, d}] != 0){
        val = min(val, funct1(b, d));
    }
    if(a == d && mp[{b, c}] != 0){
        val = min(val, funct1(b, c));
    }
    if(b == c && mp[{a, d}] != 0){
        val = min(val, funct1(a, d));
    }
    if(b == d && mp[{a, c}] != 0){
        val = min(val, funct1(a, c));
    }
    return val;
}
bool cmp(vector <int> a, vector <int> b){
    if(a[2] == b[2]){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    return a[2] < b[2];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i =0 ; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        if(u > v){
            swap(u, v);
        }
        mp[{u, v}] = mp[{v, u}] = w;
        vec.push_back({u, v, w});
    }
    int q;
    cin >> q;
    vector <vector <int> > query(q);
    for(int i = 0; i < q; i++){
        int t;
        cin >> t;
        if(t == 1){
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            if(u > v){
                swap(u, v);
            }
            query[i] = {t, u, v, w};
            vec.push_back({u, v, w});
        }
        else{
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if(u > v){
                swap(u, v);
            }
            query[i] = {t, u, v};
        }
    }
  //  cout << "A\n";
    sort(vec.begin(), vec.end(), cmp);
    vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
    for(int i = 0; i < sz(vec); i++){
        vec1[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        vec1[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    //    cout << vec[i][0] << " " << vec[i][1] << " " << vec[i][2] << "\n";
        mp1[vec[i]] = i;
    }
    for(int i = 0; i < n; i++){
        Tree1[i].resize(sz(vec1[i]));
        for(int j = 0; j < sz(vec1[i]); j++){
            pair <int, int> p = vec1[i][j];
            mp2[{i, p.X, p.Y}] = j; 
        }
    }
    for(auto p : mp){
        int u = p.X.X;
        int v = p.X.Y;
        if(u > v){
            continue;
        }
      //  cout << p.X.X << " " << p.X.Y << " " << p.Y << " " << mp1[{p.X.X, p.X.Y, p.Y}] << " " << sz(vec) << "\n";
        update(mp1[{u, v, p.Y}], 1);
        update1(u, mp2[{u, v, p.Y}], 1);
        update1(v, mp2[{v, u, p.Y}], 1);
    }
   // cout << "\n";
    cout << funct() << "\n";
    for(int i = 0; i < q; i++){
        if(query[i][0] == 1){
            int u = query[i][1];
            int v = query[i][2];
            int w = query[i][3];
            update(mp1[{u, v, w}], 1);
            update1(u, mp2[{u, v, w}], 1);
            update1(v, mp2[{v, u, w}], 1);
            mp[{u, v}] = mp[{v, u}] = w;
        }
        else{
            int u = query[i][1];
            int v = query[i][2];
            int w = mp[{u, v}];
            update(mp1[{u, v, w}], -1);
            update1(u, mp2[{u, v, w}], -1);
            update1(v, mp2[{v, u, w}], -1);
            mp[{u, v}] = mp[{v, u}] = 0;
        }
        cout << funct() << "\n";
    }
    return 0;
}