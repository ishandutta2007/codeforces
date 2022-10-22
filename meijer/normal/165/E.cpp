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

const int MX=5e6, N=22, BS=1<<N;
int n, a[MX];
bitset<MX> exists;
int ans[BS];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n) cin>>a[i];
    exists.reset();
    RE(i,n) exists[a[i]]=1;

    RE(i,BS)
        ans[i] = exists[i] ? i : -1;
    RE(i,N) RE(mask,BS) {
        if(mask & (1<<i))
            ans[mask] = max(ans[mask], ans[mask^(1<<i)]);
    }
    RE(i,n) a[i] = (~a[i])&((1<<N)-1);
    RE(i,n) cout<<(i==0?"":" ")<<ans[a[i]]; cout<<endl;
}