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
	cout.tie(NULL);
	program();
}


//===================//
//   begin program   //
//===================//

const int MX = 50000;
int n;
int x[MX][3];
int SA[MX];
int D, CE;

void sortX(int b=0, int e=n-1, int d=0, int ce=-1e8) {
	if(e < b) return;
	D = d; CE=ce;
	sort(SA+b, SA+e+1, [](int i, int j) {
		return abs(CE-x[i][D]) < abs(CE-x[j][D]);
	});
	if(d == 2) return;
	int prevX=-1e9, previ=-1;
	REP(i,b,e+1) {
		if(x[SA[i]][d] != prevX) {
			if(previ!=-1) {
				if(previ%2)
					sortX(previ,i-1,d+1,x[SA[previ-1]][d+1]);
				sortX(previ+(previ%2), i-1, d+1);
			}
			previ = i;
			prevX = x[SA[i]][d];
		}
	}
	if(previ!=-1) {
		if(previ%2)
			sortX(previ,e,d+1,x[SA[previ-1]][d+1]);
		sortX(previ+(previ%2), e, d+1);
	}
}

void program() {
	cin>>n;
	RE(i,n) cin>>x[i][0]>>x[i][1]>>x[i][2];
	RE(i,n) SA[i] = i;
	sortX();
	RE(i,n/2) {
		cout<<SA[i*2]+1<<" "<<SA[i*2+1]+1<<endl;
	}
}