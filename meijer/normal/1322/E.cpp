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

const int MX = 6e5;
int n, a[MX], b[MX], SA[MX], ans[MX];
set<ii> segments;
set<int> updatePositions;
int SEG[MX*4];
int curAns;
int minLength=0;

void buildSeg(int p=0, int l=0, int r=n-1) {
	if(l == r) {
		SEG[p] = l;
		return;
	}
	int m=(l+r)/2;
	buildSeg(p*2+1,l,m);
	buildSeg(p*2+2,m+1,r);
	SEG[p] = max(SEG[p*2+1], SEG[p*2+2]);
}
void setSeg(int i, int p=0, int l=0, int r=n-1) {
	if(i < l || i > r) return;
	if(l == r) {
		SEG[p] = -1;
		return;
	}
	int m=(l+r)/2;
	setSeg(i, p*2+1,l,m);
	setSeg(i, p*2+2,m+1,r);
	SEG[p] = max(SEG[p*2+1], SEG[p*2+2]);
}
int getSeg(int i, int j, int p=0, int l=0, int r=n-1) {
	if(SEG[p] == -1) return -1;
	if(j < l || i > r) return -1;
	if(i <= l && j >= r) return SEG[p];
	int m=(l+r)/2;
	int a=getSeg(i,j,p*2+1,l,m);
	int b=getSeg(i,j,p*2+2,m+1,r);
	return max(a,b);
}
bool isSwitching(ii p) {
	if(p.fi == p.se) {
		if(p.fi == 0) return 0;
		if(p.se == n-1) return 0;
		return 1;
	}
	return b[p.fi] != b[p.fi+1];
}
void setAnsSegment(ii p) {
	while(1) {
		int change = getSeg(p.fi, p.se);
		if(change == -1) break;
		setSeg(change);
		ans[change] = curAns;
	}
}
void updateSegment(ii p) {
	if(isSwitching(p)) {
		minLength = max(minLength, (p.se-p.fi)/2+1);
		if((p.se-p.fi+1)%2) {
			if(b[p.fi] == 1) setAnsSegment(p);
		} else {
			if(b[p.fi] == 1) setAnsSegment({p.fi,(p.se+p.fi)/2});
			else setAnsSegment({(p.se+p.fi)/2+1,p.se});
		}
	} else {
		if(b[p.fi] == 2) setAnsSegment(p);
	}
}
void addSegment(ii p) {
	if(p.se < p.fi) return;
	auto it = segments.insert(p).fi;
	bool prevExists=0, nextExists=0;
	if(it != segments.begin() && prev(it)->se == p.fi-1) prevExists=1;
	if(next(it) != segments.end() && next(it)->fi == p.se+1) nextExists=1;
	if(prevExists) {
		if(b[p.fi] == b[p.fi-1]) {
			// merge with prev
			ii segL, segC, segR;
			segL=segC=segR={INF,-INF};
			if(isSwitching(*prev(it))) segL={prev(it)->fi, p.fi-2}, segC.fi = p.fi-1;
			else segC.fi = prev(it)->fi;
			if(isSwitching(p)) segC.se = p.fi, segR={p.fi+1,p.se};
			else segC.se = p.se;
			it = segments.erase(prev(it));
			it = segments.erase(it);
			addSegment(segL);
			addSegment(segC);
			addSegment(segR);
			return;
		}
	}
	if(nextExists) {
		if(b[p.se] == b[p.se+1]) {
			// merge with next
			ii segL, segC, segR;
			segL=segC=segR={INF,-INF};
			if(isSwitching(*next(it))) segR={p.se+2, next(it)->se}, segC.se = p.se+1;
			else segC.se = next(it)->se;
			if(isSwitching(p)) segC.fi = p.se, segL={p.fi,p.se-1};
			else segC.fi = p.fi;
			it = segments.erase(it);
			it = segments.erase(it);
			addSegment(segL);
			addSegment(segC);
			addSegment(segR);
			return;
		}
	}
	if(isSwitching(p)) {
		if(prevExists && isSwitching(*prev(it))) {
			ii nSeg={prev(it)->fi,p.se};
			it = segments.erase(prev(it));
			it = segments.erase(it);
			addSegment(nSeg);
			return;
		}
		if(nextExists && isSwitching(*next(it))) {
			ii nSeg={p.fi,next(it)->se};
			it = segments.erase(it);
			it = segments.erase(it);
			addSegment(nSeg);
			return;
		}
	}
	updatePositions.insert(p.fi);
}
void set2(int i) {
	auto it = prev(segments.upper_bound({i,INF}));
	b[i] = 2;
	ii orSeg = *it;
	it = segments.erase(it);
	addSegment({orSeg.fi,i-1});
	addSegment({i,i});
	addSegment({i+1,orSeg.se});
}

void program() {
	cin>>n;
	RE(i,n) cin>>a[i];
	RE(i,n) b[i] = 1;
	RE(i,n) SA[i] = i;
	sort(SA,SA+n,[](int i, int j) {
		return a[i]>a[j];
	});
	buildSeg();
	segments.insert ({0,n-1});
	RE(i,n) {
		curAns = a[SA[i]];
		set2(SA[i]);
		if(i == n-1 || a[SA[i]] != a[SA[i+1]]) {
			for(int j:updatePositions) {
				auto it = prev(segments.upper_bound({j,INF}));
				updateSegment(*it);
			}
			updatePositions.clear();
		}
	}
	cout<<minLength<<endl;
	RE(i,n) cout<<(i==0?"":" ")<<ans[i];
	cout<<endl;
}