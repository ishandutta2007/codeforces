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

const int MX = 3e5;
int n;
int f[MX];
bitset<MX> received;

void program() {
	cin>>n;
	received.reset();
	RE(i,n) cin>>f[i], f[i]--;
	RE(i,n) if(f[i] != -1) received[f[i]] = 1;
	stack<int> st;
	int last=0;
	RE(i,n)
		if(f[i] == -1 && received[i] == 0)
			last = i;
	st.push(last);
	RE(i,n)
		if(f[i] == -1 && received[i] == 0)
			st.push(i);
	st.pop();
	if(st.size() == 1) {
		RE(i,n) {
			if(f[i] == -1 && received[i]) {
				f[i] = st.top(), st.pop();
				break;
			}
		}
		RE(i,n) if(f[i] != -1) received[f[i]] = 1;
	} else {
		REV(i,0,n)
			if(f[i] == -1 && received[i] == 0)
				f[i] = st.top(), st.pop();
		RE(i,n) if(f[i] != -1) received[f[i]] = 1;
	}
	RE(i,n)
		if(received[i] == 0)
			st.push(i);
	RE(i,n)
		if(f[i] == -1)
			f[i] = st.top(), st.pop();
	RE(i,n) cout<<(i==0?"":" ")<<f[i]+1; cout<<endl;
}