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
int n, a[MX], b[MX], c[MX];

int getMoreThen(int x) {
	int lb=0, ub=n;
	while(lb != ub) {
		int mid=(lb+ub)/2;
		if(c[mid] > x) ub = mid;
		else lb = mid+1;
	}
	return n-ub;
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	RE(i,n) cin>>b[i];
	RE(i,n) c[i] = a[i]-b[i];
	sort(c,c+n);
	ll ans=0;
	RE(i,n) {
		ans += getMoreThen(0-c[i]);
		if(c[i] >= 1) ans--;
	}
	ans /= 2;
	cout<<ans<<endl;
}