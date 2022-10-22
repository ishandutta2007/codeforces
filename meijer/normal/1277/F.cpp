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

const int MX = 1e6;
int n, a[MX];
map<int, int> cnt;
priority_queue<ii> pq;
set<ii> visited;
int dpMX[MX];

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	int mnSz=0;
	RE(i,n) cnt[a[i]]++, mnSz=max(mnSz, cnt[a[i]]);
	RE(i,n+1) dpMX[i] = 0;
	for(ii p:cnt)
		RE(i,p.se)
			dpMX[i+1]++;
	RE1(i,n) dpMX[i] += dpMX[i-1];
	int R=1, C=1;
	RE1(i,n) {
		int r = i, c = dpMX[r]/r;
		if(c < r) break;
		if(r*c > R*C)
			R=r, C=c;
	}
	cout<<R*C<<endl;
	cout<<R<<" "<<C<<endl;

	for(ii p : cnt) {
		pq.push({min(R, p.se), p.fi});
	}
	vector<vi> ans;
	vector<vector<bool>> visited;
	int visSize=0;
	ans.resize(R); visited.resize(R);
	RE(i,R) ans[i].resize(C);
	RE(i,R) visited[i].assign(C, 0);
	{
		int r=0, c=0;
		while(!pq.empty()) {
			ii p=pq.top(); pq.pop();
			RE(j,p.fi) {
				visited[r][c] = 1; visSize++;
				ans[r][c] = p.se; 
				r = (r+1)%R;
				c = (c+1)%C;
				if(visSize == R*C) break;
				while(visited[r][c]) c = (c+1)%C;
			}
			if(visSize == R*C) break;
		}
	}
	RE(i,R) {
		RE(j,C) cout<<(j==0?"":" ")<<ans[i][j];
		cout<<endl;
	}
}