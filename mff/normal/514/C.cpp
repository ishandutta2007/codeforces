#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e6 + 10;
const int64 BASE = 37;
const int64 MOD = (int64)1e9 + 7;

map<pii,char> M;
int64 AR1[MAXN];
int64 AR2[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        string s;
        cin >> s;
        AR1[0] = 0;
        AR2[SZ(s)+1] = 0;
        for (int j = 0; j < SZ(s); ++j){
            AR1[j + 1] = (BASE * AR1[j] + (s[j] - 'a' + 1)) % MOD;
            AR2[SZ(s)-j] = (BASE * AR2[SZ(s)-j+1] + (s[SZ(s)-j-1] - 'a' + 1)) % MOD;
        }
        for (int j = 0; j < SZ(s); ++j){
            pii cur = MP(AR1[j], AR2[j+2]);
            if (M.count(cur) == 0){
                M[cur] = s[j];
            }
//          else{
            else if (M[cur] != s[j]){
                M[cur] = 'x';
            }
        }
    }

    for (int i = 0; i < m; ++i){
        string s;
        cin >> s;
        AR1[0] = 0;
        AR2[SZ(s)+1] = 0;
        for (int j = 0; j < SZ(s); ++j){
            AR1[j + 1] = (BASE * AR1[j] + (s[j] - 'a' + 1)) % MOD;
            AR2[SZ(s)-j] = (BASE * AR2[SZ(s)-j+1] + (s[SZ(s)-j-1] - 'a' + 1)) % MOD;
        }
        bool ok = false;
        for (int j = 0; j < SZ(s) && !ok; ++j){
            pii cur = MP(AR1[j], AR2[j+2]);
            if (M.count(cur) == 0){
                continue;
            }
            else{
                char c = M[cur];
                if (c != s[j])
                    ok = true;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}