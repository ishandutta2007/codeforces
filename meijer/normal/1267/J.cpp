#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=3e6, MOD=1e9+7;

int t, n, c[MX];
int cnt[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	RE(i,n) cin>>c[i], c[i]--;
    	RE(i,n) cnt[i] = 0;
    	RE(i,n) cnt[c[i]]++;
    	set<int> difCnt;
    	RE(i,n) if(cnt[i]) difCnt.insert(cnt[i]);
    	int maxAns = *difCnt.begin() + 1;
    	int s=0;
    	REV(i,1,maxAns+1) {
    		bool pos=1;
    		for(int j:difCnt) {
    			if(j%i == 0) continue;
    			if((j+i-1)/i < i-j%i) {
    				pos = 0;
    				break;
    			}
    		}
    		if(pos) {
    			s = i;
    			break;
    		}
    	}
    	int ans=0;
    	RE(i,n) ans += (cnt[i]+s-1)/s;
    	cout<<ans<<endl;
    }
}