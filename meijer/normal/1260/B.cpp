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
int t, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
    	cin>>a>>b;
    	int total = a+b;
    	int moves = total/3;
    	int lb=0, ub=moves;
    	while(lb != ub) {
    		int mid=(lb+ub)/2;
    		int x=mid, y=moves-x;
    		int na = a-x-2*y;
    		if(na >= 0) ub = mid;
    		else lb = mid+1;
    	}
		int x=lb, y=moves-x;
		int na = a-x-2*y;
		int nb = b-2*x-y;
		if(na == 0 && nb == 0) {
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
    }
}