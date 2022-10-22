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

int n, k;
string a;
string b;

void program() {
	cin>>n>>k>>a;
	b.resize(n);
	bool bf=1;
	REP(i,k,n) {
		if(a[i] < a[i-k]) {
			bf = 1;
			break;
		}
		if(a[i] > a[i-k]){
			bf = 0;
			break;
		}
	}
	bool changed=0;
	int ci=0;
	REV(j,0,k) {
		char ans=a[j];
		if(!changed && !bf && ans!='9') {
			ans++;
			changed = 1;
			ci = j;
		}
		if(!changed && !bf) {
			ans = '0';
		}
		for(int i=j; i<n; i+=k) {
			b[i] = ans;
		}
	}
	cout<<n<<endl;
	cout<<b<<endl;
}