#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
#define rem_dupl(x) sort(all(x)); x.erase(unique(all(x)), x.end())
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> ii;
#define x first
#define y second

//mt19937 rand32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rand64(chrono::steady_clock::now().time_since_epoch().count());

const db eps = 1e-9;
const int maxn = (int)5e5 + 5;
const ll mod = (int)1e9 + 7; // 998244353

int a[maxn], mp[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);

    int Q, co=1;
    cin >> Q;
    multiset<int> ids;
    multiset<ii> vals;
    for(int i = 1; i <= Q; i++){
        int o, m;
        cin >> o;
        if(o == 1){
            cin >> m;
            ids.insert(co);
            vals.insert({-m,co});
            mp[m] = co;
            a[co] = m;
            co++;
        }
        if(o == 2){
            int x = *ids.begin();
            ids.erase(x);
            vals.erase(vals.find({-a[x], x}));
            cout << x << ' ';
        }
        if(o == 3){
            auto i = *vals.begin();
            vals.erase(vals.begin());
            ids.erase(i.y);
            cout << i.y << ' ';
        }
    }

    
    
    return 0;
}