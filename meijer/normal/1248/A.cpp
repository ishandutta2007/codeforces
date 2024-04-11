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

const ll MX=1e5;
ll t, n, m, p[MX], q[MX];
ll evenN=0, evenM=0, unevenN=0, unevenM=0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	RE(i,n) cin>>p[i];
    	cin>>m;
    	RE(i,m) cin>>q[i];
    	evenN=0, evenM=0, unevenN=0, unevenM=0;
    	RE(i,n) if(p[i]%2) {
    		evenN++;
    	} else {
    		unevenN++;
    	}
    	RE(i,m) if(q[i]%2) {
    		evenM++;
    	} else {
    		unevenM++;
    	}
    	cout<<(evenN*evenM + unevenM*unevenN)<<endl;
    }
}