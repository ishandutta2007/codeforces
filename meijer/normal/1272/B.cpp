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
int q, n; string s;
int a[4];

void program() {
	cin>>q;
	while(q--) {
		cin>>s; n=s.size();
		RE(i,4) a[i]=0;
		RE(i,n) {
			if(s[i]=='L') a[0]++;
			if(s[i]=='R') a[1]++;
			if(s[i]=='U') a[2]++;
			if(s[i]=='D') a[3]++;
		}
		bool hor = (a[2]==0 || a[3]==0);
		bool ver = (a[0]==0 || a[1]==0);
		if(ver && hor) {
			cout<<0<<endl;
			cout<<endl;
		} else
		if(ver) {
			cout<<2<<endl;
			cout<<"UD"<<endl;
		} else
		if(hor) {
			cout<<2<<endl;
			cout<<"LR"<<endl;
		} else {
			a[0] = min(a[0], a[1]);
			a[2] = min(a[2], a[3]);
			cout<<a[0]*2+a[2]*2<<endl;
			RE(i,a[0]) cout<<"L";
			RE(i,a[2]) cout<<"U";
			RE(i,a[0]) cout<<"R";
			RE(i,a[2]) cout<<"D";
			cout<<endl;
		}
	}
}