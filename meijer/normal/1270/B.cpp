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

const int MX = 5e5;
int t, n, a[MX], dpMX[MX], dpMN[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		RE(i,n) cin>>a[i];
		dpMX[n-1] = n-1;
		dpMN[n-1] = n-1;
		REV(i,0,n-1) {
			dpMX[i] = ( a[i]-i >  a[dpMX[i+1]]-dpMX[i+1] ? i : dpMX[i+1]);
			dpMN[i] = (-a[i]-i > -a[dpMN[i+1]]-dpMN[i+1] ? i : dpMN[i+1]);
		}
		bool found=0;
		int u, v;
		RE(i,n) {
			if(a[dpMX[i]]-dpMX[i]-a[i]+i-1 >= 0) {
				u = i;
				v = dpMX[i];
				found=1;
				break;
			}
			if(a[i]-a[dpMN[i]]-dpMN[i]+i-1 >= 0) {
				u = i;
				v = dpMN[i];
				found=1;
				break;
			}
		}
		if(found) cout<<"YES"<<endl<<u+1<<" "<<v+1<<endl;
		else cout<<"NO"<<endl;
	}
}