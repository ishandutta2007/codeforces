#include <bits/stdc++.h>
using namespace std;

//macros
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

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX=3e5;
int t, n, a[MX], cnt[MX];

bool possible(int x) {
	multiset<int> ms;
	RE(i,x+1) {
		if(n+i <= n*2)
			ms.insert(cnt[n*2]-cnt[n+i]);
		if(n-x+i >= 0)
			if(ms.count(-cnt[n-x+i]))
				return 1;
	}
	return 0;
}

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		RE(i,n*2) cin>>a[i], a[i] = (a[i] == 2 ? -1 : 1);
		cnt[0] = 0;
		RE(i,n*2) cnt[i+1] = cnt[i] + a[i];
		int lb=0, ub=n*2;
		while(lb != ub) {
			int mid=(lb+ub)/2;
			if(possible(mid)) ub = mid;
			else lb = mid+1;
		}
		cout<<lb<<endl;
	}
}