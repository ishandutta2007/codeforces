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
int t, n, q[MX], a[MX];
bitset<MX> used;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	RE(i,n) cin>>q[i];
    	RE(i,n) a[i] = -1, used[i+1] = 0;
    	int curMx = 0;
    	RE(i,n) {
    		if(q[i] > curMx) {
    			curMx = q[i];
    			a[i] = curMx;
    			used[curMx] = 1;
    		}
    	}
    	int x=1;
    	RE(i,n) {
    		if(a[i] == -1) {
    			while(used[x]) x++;
    			a[i] = x;
    			used[x] = 1;
    		}
    	}
    	bool pos = 1;
    	curMx = 0;
    	RE(i,n) {
    		curMx = max(curMx, a[i]);
    		if(curMx > q[i]) pos = 0;
    	}
    	if(pos) {
    		RE(i,n) cout<<(i==0?"":" ")<<a[i]; cout<<endl;
    	} else {
    		cout<<-1<<endl;
    	}
    }
}