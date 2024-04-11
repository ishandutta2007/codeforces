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

int t, n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>n;
    	int sqrt=0;
    	set<int> ans;
    	while(sqrt*sqrt <= n) sqrt++; sqrt--;
    	RE(i,sqrt+1) ans.insert(i);
    	REP(i,1,sqrt+1) {
    		ans.insert(n / i);
    	}
    	cout<<ans.size()<<endl;
    	bool first=1;
    	for(int i:ans) {
    		if(first) first = 0;
    		else cout<<" ";
    		cout<<i;
    	}
    	cout<<endl;
    }
}