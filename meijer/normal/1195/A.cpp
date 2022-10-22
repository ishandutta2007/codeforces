#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e3, MOD=1e9+7;
int n, k, cnt[MX], a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    RE(i,k) cnt[i]=0;
    RE(i,n) cin>>a, a--, cnt[a]++;
    int ans=0, odd=0;
    RE(i,k) ans += (cnt[i]/2)*2, odd += cnt[i]%2;
    ans += odd/2;
    ans += odd%2;
    cout<<ans<<endl;
}