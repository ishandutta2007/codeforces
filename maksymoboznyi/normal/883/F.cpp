#include<bits/stdc++.h>
#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lg2(x) __lg(x)
#define rem_dupl(x) sort(all(x)); x.erase(unique(all(x)), x.end())
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> ii;
#define x first
#define y second

//mt19937 rand32(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rand64(chrono::steady_clock::now().time_since_epoch().count());

const db eps = 1e-9;
const int maxn = (int)2e5 + 5;
const ll mod = (int)1e9 + 7; // 998244353

int par[505], nCC;
string s[505];

int rootfind(int u){
    if(u == par[u])
        return u;
    return par[u] = rootfind(par[u]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(0);
    int n;
    cin >> n;
    set<string> q;
    while (n--) {
        string s;
        cin >> s;
        string a = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'u')
                a += "oo";
            else {
                if (s[i] == 'h')
                    while (a.size() > 0 && a.back() == 'k')
                        a.pop_back();
                a += s[i];
            }
        }
        q.insert(a);
    }
    cout << q.size();
    return 0;
}