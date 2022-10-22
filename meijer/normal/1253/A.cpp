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
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=4e5, MOD=1e9+7;
int t, n, a[MX], b[MX], c[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	RE(i,n) cin>>a[i];
    	RE(i,n) cin>>b[i];
    	RE(i,n) c[i] = b[i]-a[i];
    	int l=n, r=0;
    	RE(i,n) if(c[i] != 0) {
    		l = i;
    		break;
    	}
    	REV(i,0,n) if(c[i] != 0) {
    		r = i;
    		break;
    	}
    	bool pos=1;
    	REP(i,l,r) {
    		if(c[i] != c[i+1])
    			pos = 0;
    	}
    	if(l != n && c[l] < 0) pos = 0;
    	cout<<(pos?"YES":"NO")<<endl;
    }
}