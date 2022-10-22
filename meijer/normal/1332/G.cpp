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
#define sz size()
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

const int MX = 3e5;
int n, q, a[MX], l[MX], r[MX];
stack<ii> mxStack, mnStack;
set<int> inMxStack, inMnStack, inNeither;
int curMxStackFront=0;
int SL[MX];
vi ans[MX];
int SEGMX[MX*4], SEGMN[MX*4];

int getMx(int i, int j) {
	return a[i] > a[j] ? i : j;
}
int getMn(int i, int j) {
	return a[i] < a[j] ? i : j;
}
void buildSeg(int p=0, int l=0, int r=n-1) {
	if(l == r) {
		SEGMX[p] = l;
		SEGMN[p] = l;
		return;
	}
	int m=(l+r)/2;
	buildSeg(p*2+1,l,m);
	buildSeg(p*2+2,m+1,r);
	SEGMX[p] = getMx(SEGMX[p*2+1], SEGMX[p*2+2]);
	SEGMN[p] = getMn(SEGMN[p*2+1], SEGMN[p*2+2]);
}
int getMax(int i, int j, int p=0, int l=0, int r=n-1) {
	if(j < l || i > r) return i;
	if(i <= l && j >= r) return SEGMX[p];
	int m=(l+r)/2;
	int a=getMax(i,j,p*2+1,l,m);
	int b=getMax(i,j,p*2+2,m+1,r);
	return getMx(a,b);
}
int getMin(int i, int j, int p=0, int l=0, int r=n-1) {
	if(j < l || i > r) return i;
	if(i <= l && j >= r) return SEGMN[p];
	int m=(l+r)/2;
	int a=getMin(i,j,p*2+1,l,m);
	int b=getMin(i,j,p*2+2,m+1,r);
	return getMn(a,b);
}

void program() {
	cin>>n>>q;
	RE(i,n) cin>>a[i];
	RE(i,q) cin>>l[i]>>r[i], l[i]--, r[i]--;
	RE(i,q) SL[i]=i;
	sort(SL, SL+q, [](int i, int j){
		return l[i]>l[j];
	});

	buildSeg();

	// answer is 4
	set<ii, greater<ii>> curQ;
	RE(i,q) curQ.insert({r[i], i});
	int curSL=0;
	REV(i,0,n) {
		while(curSL != q && l[SL[curSL]] > i) {
			curQ.erase({r[SL[curSL]], SL[curSL]});
			curSL++;
		}
		while(!mxStack.empty() && a[i] > a[mxStack.top().fi]) {
			int rem = mxStack.top().fi;
			inMxStack.erase(rem);
			if(!inMnStack.count(rem)) inNeither.insert(rem);
			mxStack.pop();
		}
		while(!mnStack.empty() && a[i] < a[mnStack.top().fi]) {
			int rem = mnStack.top().fi;
			inMnStack.erase(rem);
			if(!inMxStack.count(rem)) inNeither.insert(rem);
			mnStack.pop();
		}
		if(mxStack.empty()) {
			mxStack.push({i,-1});
		} else {
			if(a[mxStack.top().fi] == a[i]) mxStack.push({i,mxStack.top().se});
			else mxStack.push({i,mxStack.top().fi});
		}
		if(mnStack.empty()) {
			mnStack.push({i,-1});
		} else {
			if(a[mnStack.top().fi] == a[i]) mnStack.push({i,mnStack.top().se});
			else mnStack.push({i,mnStack.top().fi});
		}
		if(mnStack.top().se!=-1 && mxStack.top().se!=-1) {
			int firstPos = max(mnStack.top().se, mxStack.top().se);
			auto it = inNeither.lower_bound(firstPos);
			if(it != inNeither.end()) {
				int j = *it;
				// answer queries in range i...j
				while(!curQ.empty()) {
					ii p = *curQ.begin();
					if(p.fi < j) break;
					int mn=getMin(i,j), mx=getMax(i,j);
					ans[p.se].pb(i);
					ans[p.se].pb(min(mn,mx));
					ans[p.se].pb(max(mn,mx));
					ans[p.se].pb(j);
					curQ.erase(p);
				}
			}
		}
		inMxStack.insert(i);
		inMnStack.insert(i);
	}

	// answer is 3
	curQ.clear();
	RE(i,q) if(ans[i].size() == 0) curQ.insert({r[i], i});
	curSL=0;
	while(!mnStack.empty()) mnStack.pop();
	while(!mxStack.empty()) mxStack.pop();
	inMnStack.clear(); inMxStack.clear(); inNeither.clear();
	REV(i,0,n) {
		while(curSL != q && l[SL[curSL]] > i) {
			curQ.erase({r[SL[curSL]], SL[curSL]});
			curSL++;
		}
		while(!mxStack.empty() && a[i] > a[mxStack.top().fi]) {
			int rem = mxStack.top().fi;
			inMxStack.insert(rem);
			mxStack.pop();
		}
		while(!mnStack.empty() && a[i] < a[mnStack.top().fi]) {
			int rem = mnStack.top().fi;
			inMnStack.insert(rem);
			mnStack.pop();
		}
		if(mxStack.empty()) {
			mxStack.push({i,-1});
		} else {
			if(a[mxStack.top().fi] == a[i]) mxStack.push({i,mxStack.top().se});
			else mxStack.push({i,mxStack.top().fi});
		}
		if(mnStack.empty()) {
			mnStack.push({i,-1});
		} else {
			if(a[mnStack.top().fi] == a[i]) mnStack.push({i,mnStack.top().se});
			else mnStack.push({i,mnStack.top().fi});
		}
		if(mnStack.top().se!=-1) {
			int firstPos = mnStack.top().se;
			auto it = inMnStack.lower_bound(firstPos);
			if(it != inMnStack.end()) {
				int j = *it;
				// answer queries in range i...j
				while(!curQ.empty()) {
					ii p = *curQ.begin();
					if(p.fi < j) break;
					ans[p.se].pb(i);
					ans[p.se].pb(getMin(i,j));
					ans[p.se].pb(j);
					curQ.erase(p);
				}
			}
		}
		if(mxStack.top().se!=-1) {
			int firstPos = mxStack.top().se;
			auto it = inMxStack.lower_bound(firstPos);
			if(it != inMxStack.end()) {
				int j = *it;
				// answer queries in range i...j
				while(!curQ.empty()) {
					ii p = *curQ.begin();
					if(p.fi < j) break;
					ans[p.se].pb(i);
					ans[p.se].pb(getMax(i,j));
					ans[p.se].pb(j);
					curQ.erase(p);
				}
			}
		}
	}
	RE(i,q) {
		cout<<ans[i].size()<<endl;
		RE(j,ans[i].size()) cout<<(j==0?"":" ")<<ans[i][j]+1; cout<<endl;
	}
}