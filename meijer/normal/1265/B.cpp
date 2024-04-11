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
int p[MX], a[MX], t, n, l, r;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	RE(i,n) cin>>p[i], p[i]--;
    	RE(i,n) a[p[i]] = i;
    	l = r = a[0];
    	RE(i,n) {
    		bool pos=0;
    		l = min(l, a[i]);
    		r = max(r, a[i]);
    		pos = (r - l) == i;
    		cout<<pos;
    	}
    	cout<<endl;
    }
}