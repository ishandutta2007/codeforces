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

const int MX=1000, MOD=1e9+7;
int T, n, m, a[MX], sz[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
    	cin>>n>>m;
    	RE(i,n) cin>>a[i];
    	if(n <= 2 || m < n) {
    		cout<<-1<<endl;
    		continue;
    	}
    	int minEdge = INF, x, y;
    	RE(i,n) RE(j,n) if(i != j && a[i]+a[j] < minEdge) {
    		minEdge = a[i]+a[j];
    		x = i; y = j;
    	}
    	int minCost = 0;
    	RE(i,n) minCost += 2*a[i];
    	minCost += minEdge*(m-n);
    	cout<<minCost<<endl;
    	RE(i,n) {
    		cout<<i+1<<" "<<(i+1)%n+1<<endl;
    	}
    	RE(i,m-n) {
    		cout<<x<<" "<<y<<endl;
    	}
    }
}