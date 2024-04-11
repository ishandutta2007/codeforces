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

const int MX = 418;
int n;
string s;

void program() {
	cin>>n;
	RE(i,n) {
		cin>>s;
		int sm=0;
		for(char c:s) sm += c-'0';
		int cnt[10];
		RE(i,10) cnt[i] = 0;
		for(char c:s) cnt[c-'0']++;
		bool pos = cnt[0] > 0;
		bool twent = cnt[0] > 1;
		REP(i,1,5) if(cnt[i*2]) twent=1;
		pos = pos&&twent;
		if(sm % 3) pos = 0;
		cout<<(pos?"red":"cyan")<<endl;
	}
}