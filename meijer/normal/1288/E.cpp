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
//End added libraries//
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

const int MX = 3e5+1e4;
int n, m, a[MX];
int beg[MX], End[MX];
int sum[MX];
int BIT[MX];
int lastVisit[MX];
priority_queue<ii, vii, greater<ii>> pq;

void update(int i, int val) {
	for(i++; i<=m; i+=i&-i)
		BIT[i] += val;
}
int query(int i) {
	int ans=0;
	for(i++; i>0; i-=i&-i)
		ans += BIT[i];
	return ans;
}

void program() {
	cin>>n>>m;
	RE(i,n) beg[i]=i, End[i]=i;
	RE(i,m) cin>>a[i], a[i]--;

	RE(i,m) beg[a[i]] = 0;
	RE(i,MX) BIT[i] = 0;
	RE(i,n) lastVisit[i] = m;
	REV(i,0,m) {
		pq.push({lastVisit[a[i]], i});
		lastVisit[a[i]] = i;
	}
	RE(i,n) lastVisit[i] = -1;
	RE(i,m) {
		if(lastVisit[a[i]] != -1) {
			update(lastVisit[a[i]], -1);
		}
		lastVisit[a[i]] = i;
		update(lastVisit[a[i]], 1);
		while(!pq.empty() && pq.top().fi == i) {
			ii p = pq.top(); pq.pop();
			int u = a[p.se];
			End[u] = max(End[u], query(p.fi-1)-query(p.se));
		}
	}
	while(!pq.empty()) {
		ii p = pq.top(); pq.pop();
		int u = a[p.se];
		End[u] = max(End[u], query(p.fi-1)-query(p.se));
	}

	RE(i,MX) BIT[i] = 0;
	int first[MX];
	RE(i,n) first[i] = m;
	REV(i,0,m) first[a[i]] = i;
	REV(i,0,n) {
		update(first[i], 1);
		End[i] = max(End[i], i+query(first[i]-1));
	}

	RE(i,n)
		cout<<beg[i]+1<<" "<<End[i]+1<<endl;
}