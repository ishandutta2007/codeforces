#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e4, K=24, BS=1<<K;
int n, A[BS], dp[BS];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,BS) A[i]=0;
    RE(i,n) {
        cin>>s; sort(s.begin(), s.end());
        int bs[3];
        RE(j,3)
            bs[j] = 1<<(s[j]-'a');
        A[bs[0]|bs[1]|bs[2]]++;
    }

    RE(i,BS) dp[i] = A[i];
    RE(i,K)
        RE(mask,BS)
            if(mask & (1<<i))
                dp[mask] += dp[mask^(1<<i)];
    int ans=0;
    RE(i,BS) ans ^= ((n-dp[i])*(n-dp[i]));
    cout<<ans<<endl;
}