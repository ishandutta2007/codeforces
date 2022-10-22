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

const int MX=2e5, MOD=1e9+7;
int n, q[MX][3], ans[MX];
set<int> insideQ[MX];
bitset<MX> found;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    RE(i,n-2) RE(j,3) cin>>q[i][j];
    RE(i,n-2) RE(j,3) {
    	insideQ[q[i][j]].insert(i);
    }
    RE1(i,n)
    	if(insideQ[i].size() == 1)
    		ans[0] = i;
   	{
	    int j = *insideQ[ans[0]].begin();
		RE(k,3) {
	    	if(insideQ[q[j][k]].size() == 2)
	    		ans[1] = q[j][k];
	    }
	}
    found.reset(); found[ans[0]]=found[ans[1]]=1;
    REP(i,0,n-2) {
    	int j = *insideQ[ans[i]].begin();
		RE(k,3) {
			insideQ[q[j][k]].erase(j);
			if(!found[q[j][k]]) {
				found[q[j][k]]=1;
				ans[i+2] = q[j][k];
			}
		}
    }
    RE(i,n) cout<<(i==0?"":" ")<<ans[i]; cout<<endl;
}