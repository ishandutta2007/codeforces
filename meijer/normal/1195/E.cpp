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

const int MX=3e3, MOD=1e9+7;
ll n, m, a, b, g0, x, y, z;
int gr[MX][MX];
int minR[MX][MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>a>>b;
    cin>>g0>>x>>y>>z;
    RE(i,n) RE(j,m) {
    	gr[i][j] = g0;
    	g0 = (g0*x + y)%z;
    }
    RE(i,n) {
    	deque<int> q;
    	REV(j,0,m) {
    		while(!q.empty() && q.back() > gr[i][j])
    			q.pop_back();
    		q.push_back(gr[i][j]);
    		int k = j+b;
    		if(k < m && !q.empty() && q.front() == gr[i][k])
    			q.pop_front();
    		minR[i][j] = q.front();
    	}
    }

    ll ans = 0;
    RE(j,m-b+1) {
    	deque<int> q;
	    REV(i,0,n) {
    		while(!q.empty() && q.back() > minR[i][j])
    			q.pop_back();
    		q.push_back(minR[i][j]);
    		int k = i+a;
    		if(k < n && !q.empty() && q.front() == minR[k][j])
    			q.pop_front();
    		if(k <= n) ans += q.front();
	    }
    }
    cout<<ans<<endl;
}