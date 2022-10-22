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

const int MX = 1e5+100;
int n;
int sa[MX], sb[MX], ea[MX], eb[MX];
int SEGMX[MX*4], SEGMN[MX*4];
int SA[MX], SAR[MX];

void buildSeg(int p=0, int l=0, int r=n-1) {
	SEGMN[p] = INF;
	SEGMX[p] = 0;
	if(l != r) {
		int m=(l+r)/2;
		buildSeg(p*2+1,l,m);
		buildSeg(p*2+2,m+1,r);
	}
}
void addSeg(int i, int v, int f, int p=0, int l=0, int r=n-1) {
	if(i < l || i > r) return;
	if(l == r) {
		SEGMN[p] = v;
		SEGMX[p] = f;
		return;
	}
	int m=(l+r)/2;
	addSeg(i,v,f,p*2+1,l,m);
	addSeg(i,v,f,p*2+2,m+1,r);
	SEGMN[p] = min(SEGMN[p*2+1], SEGMN[p*2+2]);
	SEGMX[p] = max(SEGMX[p*2+1], SEGMX[p*2+2]);
}
int getMax(int i, int j, int p=0, int l=0, int r=n-1) {
	if(j < l || i > r) return 0;
	if(i <= l && j >= r) return SEGMX[p];
	int m=(l+r)/2;
	int a=getMax(i,j,p*2+1,l,m);
	int b=getMax(i,j,p*2+2,m+1,r);
	return max(a,b);
}
int getMin(int i, int j, int p=0, int l=0, int r=n-1) {
	if(j < l || i > r) return INF;
	if(i <= l && j >= r) return SEGMN[p];
	int m=(l+r)/2;
	int a=getMin(i,j,p*2+1,l,m);
	int b=getMin(i,j,p*2+2,m+1,r);
	return min(a,b);
}

void program() {
	cin>>n;
	RE(i,n) {
		cin>>sa[i]>>ea[i]>>sb[i]>>eb[i];
	}
	bool ans=1;
	RE(q,2) {
		priority_queue<iii, viii, greater<iii>> pq;
		RE(i,n) {
			pq.push({sa[i],0,i});
			pq.push({ea[i],1,i});
		}
		RE(i,n) SA[i] = i;
		sort(SA, SA+n, [](int i, int j) {
			return sb[i] < sb[j];
		});
		RE(i,n) SAR[SA[i]] = i;
		buildSeg();

		while(!pq.empty()) {
			int u, type, i;
			tie(u, type, i) = pq.top(); pq.pop();
			if(type == 0) {
				//begin
				int j = SAR[i];
				int ebj = getMin(0,j);
				if(sb[i] > ebj) {
					ans = 0;
					break;
				}
				int sbj = getMax(j,n-1);
				if(sbj > eb[i]) {
					ans = 0;
					break;
				}
				addSeg(SAR[i], eb[i], sb[i]);
			} else {
				//end
				addSeg(SAR[i], INF, 0);
			}
		}
		if(ans == 0) break;
		RE(i,n) {
			swap(sa[i], sb[i]);
			swap(ea[i], eb[i]);
		}
	}
	cout<<(ans?"YES":"NO")<<endl;
}