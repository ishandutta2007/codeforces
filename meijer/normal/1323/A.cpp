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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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
int t, n, a[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		RE(i,n) cin>>a[i];
		bool s=0;
		RE(i,n) {
			bool p=a[i]%2;
			if(p == 0) {
				cout<<1<<endl;
				cout<<i+1<<endl;
				s=1;
				break;
			}
		}
		if(s) continue;
		if(n >= 2) {
			cout<<2<<endl;
			cout<<"1 2"<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
}