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

const int MX=2e5, MOD=1e9+7;
int T, n, a[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
    	cin>>n;
    	RE(i,n) cin>>a[i];
    	int minAns = n;
    	map<int, int> last;
    	RE(i,n) {
    		if(last.find(a[i]) != last.end()) {
    			minAns = min(minAns, i - last[a[i]]);
    		}
    		last[a[i]] = i;
    	}
    	if(minAns == n) minAns = -1;
    	else minAns++;
    	cout<<minAns<<endl;
    }
}