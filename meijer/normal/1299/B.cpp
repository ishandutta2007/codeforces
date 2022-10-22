#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
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

const int MX = 5e5;
int n, x[MX], y[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>x[i]>>y[i];
	bool pos = (n%2 == 0);
	if(pos) {
		int m=n/2;
		RE(i,m) {
			int dx1=x[i+1]-x[i];
			int dy1=y[i+1]-y[i];
			int dx2, dy2;
			if(i == m-1) {
				dx2 = x[m+i]-x[0];
				dy2 = y[m+i]-y[0];
			} else {
				dx2 = x[m+i]-x[m+i+1];
				dy2 = y[m+i]-y[m+i+1];
			}
			if(dx1 != dx2 || dy1 != dy2) pos = 0;
		}
	}
	cout<<(pos?"YES":"NO")<<endl;
}