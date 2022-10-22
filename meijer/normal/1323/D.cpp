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
int n;
int a[MX], b[MX];

int getNumbersBetween(int i, int j) {
	return upper_bound(b,b+n,j)-lower_bound(b,b+n,i);
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	int ans=0;
	RE(k,26) {
		int bit = (1<<k);
		int mx = bit*2;
		RE(i,n) b[i] = a[i]%mx;
		sort(b,b+n);
		int cnt=0;
		RE(i,n) {
			int lb = bit-b[i];
			int ub = mx-b[i]-1;
			cnt += getNumbersBetween(lb, ub);
			if(lb <= b[i] && b[i] <= ub) cnt--;
			lb = mx+bit-b[i];
			ub = mx+mx-b[i]-1;
			cnt += getNumbersBetween(lb, ub);
			if(lb <= b[i] && b[i] <= ub) cnt--;
		}
		cnt /= 2;
		if(cnt%2) ans |= bit;
	}
	cout<<ans<<endl;
}