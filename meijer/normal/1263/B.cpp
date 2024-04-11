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

const int MX=4e5, MOD=1e9+7;
int T, n;
string p[10];
set<string> s, t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
    	cin>>n;
    	RE(i,n) cin>>p[i];
    	t.clear(); RE(i,n) t.insert(p[i]);
    	s.clear();
    	int changes=0;
    	RE(i,n) {
    		if(s.count(p[i])) {
    			changes++;
    			RE(j,10) {
    				p[i][0] = '0'+j;
    				if(!t.count(p[i]))
    					break;
    			}
    		}
    		s.insert(p[i]);
    		t.insert(p[i]);
    	}
    	cout<<changes<<endl;
    	RE(i,n) cout<<p[i]<<endl;
    }
}