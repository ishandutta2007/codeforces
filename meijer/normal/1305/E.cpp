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
int n, m, a[MX];

void program() {
	cin>>n>>m;
	int max=0;
	RE(i,n) {
		max += i/2;
	}
	if(m > max) {
		cout<<-1<<endl;
		return;
	}

	int cur=1, big=2;
	RE(i,n) {
		if(m > 0) {
			if(m - i/2 < 0) {
				int curAdd = i/2;
				int dif = curAdd-m;
				cur += dif*2;
				big = cur + 1;
				m = 0;
			} else {
				m -= i/2;
				if(m == 0) big = cur + 1;
			}
		}
		a[i] = cur;
		if(m > 0) cur++;
		else cur += big;
	}

	RE(i,n) cout<<(i==0?"":" ")<<a[i]; cout<<endl;
}