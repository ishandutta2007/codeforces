#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout << #x << "=" << x << endl
#define MP make_pair

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-7;
const int oo = 1 << 30;

vector< pair<pii,int> > V;
multiset< pair<pii,int> > S;
int ANS[110];

int main()
{
    int n; cin >> n;
    int m = oo, M = 0;
    for (int i = 0; i < n; ++i){
        int b, e; cin >> b >> e;
        m = min(m, b);
        M = max(M, e);
        V.push_back( MP( MP(b, e), i) );
    }
    sort(V.begin(), V.end());
    int p = 0, a = 0;
    for (int i = m; i <= M && a < n; ++i){
        while (p < n && i == V[p].first.first){
            pair<pii, int> mypair = MP(MP(V[p].first.second,V[p].first.first), V[p].second);
            S.insert(mypair);
            p++;
        }
        if (!S.empty()){
            pair<pii, int> cur = *S.begin();
            ANS[cur.second] = i;
            a++;
            S.erase(S.begin());
        }
    }
    for (int i = 0; i < n; ++i)
        cout << ANS[i] << " \n"[i == n - 1];
    return 0;
}