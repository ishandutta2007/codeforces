#include <bits/stdc++.h>
using namespace std;

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

const int MX=1e6, MOD=1e9+7;
int n, x, tot=0;
string s, t;
int SEGMIN[MX*4], SEGMAX[MX*4], LAZY[MX*4];

void buildSeg(int p=0, int l=0, int r=n-1) {
	SEGMIN[p] = SEGMAX[p] = LAZY[p] = 0;
	if(l == r) return;
	int m=(l+r)/2;
	buildSeg(p*2+1,l,m);
	buildSeg(p*2+2,m+1,r);
}
void addSeg(int i, int j, int v, int lazy=0,int p=0,int l=0, int r=n-1) {
	SEGMIN[p] += lazy;
	SEGMAX[p] += lazy;
	LAZY[p] += lazy;
	if(j < l || i > r) return;
	if(i <= l && j >= r) {
		SEGMIN[p] += v;
		SEGMAX[p] += v;
		LAZY[p] += v;
	} else {
		int m=(l+r)/2;
		addSeg(i,j,v,LAZY[p],p*2+1,l,m);
		addSeg(i,j,v,LAZY[p],p*2+2,m+1,r);
		SEGMIN[p] = min(SEGMIN[p*2+1], SEGMIN[p*2+2]);
		SEGMAX[p] = max(SEGMAX[p*2+1], SEGMAX[p*2+2]);
		LAZY[p] = 0;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>s; x=0;
    t.assign(n,' ');
    RE(i,n) {
    	cout<<(i==0?"":" ");
    	if(s[i] != 'L' && s[i] != 'R') {
	    	if(t[x] == ')') {
	    		addSeg(x,n-1,1);
	    		tot += 1;
	    	}
	    	if(t[x] == '(') {
	    		addSeg(x,n-1,-1);
	    		tot -= 1;
	    	}
    		t[x] = s[i];
    	}
    	if(s[i] == '(') {
    		addSeg(x,n-1,1);
    		tot += 1;
    	}
    	if(s[i] == ')') {
    		addSeg(x,n-1,-1);
    		tot -= 1;
    	}
    	if(s[i] == 'L') {
    		x--;
    		if(x < 0) x=0;
    	}
    	if(s[i] == 'R') {
    		x++;
    	}
    	if(SEGMIN[0] < 0 || tot != 0) {
    		cout<<-1;
    	} else {
    		cout<<SEGMAX[0];
    	}
    }
    cout<<endl;
}