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

const int MX = 1e6;

int n, x;
int a[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	ll ans1=0, ans2=0;
	RE(i,n) {
		if(i%2) {
			ans1 += a[i]/2;
			ans2 += (a[i]+1)/2;
		} else {
			ans2 += a[i]/2;
			ans1 += (a[i]+1)/2;
		}
	}
	cout<<min(ans1,ans2)<<endl;
}