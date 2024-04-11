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
int a[4], A[4], n=0;
vi ans;

void printAns() {
	cout<<"YES"<<endl;
	RE(i,n) cout<<(i==0?"":" ")<<ans[i];
	cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    RE(i,4) cin>>a[i];
    RE(i,4) n += a[i];
    bool pos=1;
    ans.reserve(n);
    RE(b,4) {
    	pos=1;
	    RE(i,4) A[i]=a[i];
	    int p=b;
	    RE(i,n) {
	    	ans.pb(p);
	    	A[p]--;
	    	if(A[p] < 0) pos=0;
	    	if(p == 0) p++;
	    	else if(p == 3) p--;
	    	else {
	    		if(A[p-1] != 0)
	    			p--;
	    		else
	    			p++;
	    	}
	    }
	    if(pos) {
	    	printAns();
	    	return 0;
	    } else ans.clear();
	}
	cout<<"NO"<<endl;
}