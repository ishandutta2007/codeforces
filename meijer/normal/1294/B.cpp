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

const int MX = 2000;
int t, n, x[MX], y[MX], SA[MX];

void program() {
	cin>>t;
	while(t--) {
		cin>>n;
		RE(i,n) cin>>x[i]>>y[i];
		RE(i,n) SA[i] = i;
		sort(SA, SA+n, [](int i, int j) {
			if(x[i] != x[j])
				return x[i] < x[j];
			return y[i] < y[j];
		});
		int X=0, Y=0;
		bool pos=1;
		queue<char> ans;
		RE(i,n) {
			int tx=x[SA[i]], ty=y[SA[i]];
			if(X > tx) {pos=0; break;}
			if(Y > ty) {pos=0; break;}
			while(X < tx) X++, ans.push('R');
			while(Y < ty) Y++, ans.push('U');
		}
		if(pos) {
			cout<<"YES"<<endl;
			while(!ans.empty()) {
				cout<<ans.front(); ans.pop();
			}
			cout<<endl;
		} else {
			cout<<"NO"<<endl;
		}
	}
}