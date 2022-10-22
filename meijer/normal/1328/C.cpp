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
#define sz size()
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
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
int t, n;
string s;

void program() {
	cin>>t;
	while(t--) {
		cin>>n>>s;
		string a; a.resize(n);
		string b; b.resize(n);
		bool started=0;
		RE(i,n) {
			if(s[i] == '0') a[i]='0', b[i]='0';
			if(s[i] == '1') {
				if(started) a[i]='1', b[i]='0';
				else a[i]='0', b[i]='1', started=1;
			}
			if(s[i] == '2') {
				if(started) a[i]='2', b[i]='0';
				else a[i]='1', b[i]='1';
			}
		}
		cout<<a<<endl;
		cout<<b<<endl;
	}
}