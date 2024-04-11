#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef long double ld;
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

const int MX = 1e6+1e5;
int n, a[MX];
ll sm[MX];
double b[MX];
int beg[MX];
int l[MX];

void updateB(int i, int len) {
	b[i] = double(sm[i+len-1]-(i==0 ? 0 : sm[i-1]))/double(len);
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	RE(i,n) b[i] = a[i];
	sm[0] = a[0];
	REP(i,1,n) sm[i] = sm[i-1]+a[i];
	RE(i,n) beg[i] = i, l[i]=1;
	RE(i,n-1) {
		int j = beg[i];
		if(b[j] >= b[i+1]) {
			l[j]++;
			updateB(j, l[j]);
			while(j != 0 && b[beg[j-1]] >= b[j]) {
				l[beg[j-1]] += l[j];
				j = beg[j-1];
				updateB(j, l[j]);
			}
			beg[i+1] = j;
		}
	}
	int i=0;
	while(i != n) {
		RE(j,l[i]) b[i+j] = b[i];
		i += l[i];
	}
	RE(i,n) printf("%.9f\n", b[i]);
}