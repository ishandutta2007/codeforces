#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int X; scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define RF(x) freopen(x,"r",stdin)
#define WF(x) freopen(x,"w",stdout)
#define loop(I, A, B) for (int I = (A); I <= (B); ++I)
typedef long long LL;
using namespace std;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
const LL MOD = (LL)1e9+7;
const int SIZE = 1000002;
const LL INF = 1LL<<30;
const double eps = 1e-6;
const double PI=3.1415926535897932;

template<int MOD>
struct ModInt {
  unsigned x;
  ModInt() : x(0) { }
  ModInt(signed sig) : x(sig%MOD) {  }
  ModInt(signed long long sig) : x(sig%MOD) { }
  int get() const { return (int)x; }
  ModInt pow(LL p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }
 
  ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
  ModInt &operator/=(ModInt that) { return (*this) *= that.pow(MOD - 2); }
 
  ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
  ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
  ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
  ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
  bool operator<(ModInt that) const { return x < that.x; }
  friend ostream& operator<<(ostream &os, ModInt a) { os << a.x; return os; }
};
typedef ModInt<(int)1e9+7> mint;
typedef pair<mint,mint> PMM;

int d[200009];
unordered_map<int, vector<int>> p;
int e[200009],root[200009];

struct node{
	int cnt,lc,rc;
    LL sum;
    PMM hh;//hashsums
}tree[4000009];

int nc=0;
int create_node(int _lc,int _rc,int _cnt, LL _sum, PMM ph, PMM nh){
	int idx=++nc;
	tree[idx].lc=_lc;
	tree[idx].rc=_rc;
	tree[idx].cnt=_cnt;
	tree[idx].sum=_sum;
    tree[idx].hh = {ph.F+nh.F, ph.S+nh.S};
	return idx;
}

void up(int &root,int proot,int s,int e,int x,int v,PMM nh){
	root=create_node(tree[proot].lc,tree[proot].rc,tree[proot].cnt+1,tree[proot].sum+v,tree[proot].hh,nh);
	if(s==e)return;
	int m=(s+e)>>1;
	if(x>m)up(tree[root].rc,tree[proot].rc,m+1,e,x,v,nh);
	else up(tree[root].lc,tree[proot].lc,s,m,x,v,nh);
}

int quCnt(int l,int r,int s,int e,int x,int y){
	if(s==x&&e==y)return tree[r].cnt-tree[l].cnt;
	int m=(s+e)>>1;
	if(x>m)return quCnt(tree[l].rc,tree[r].rc,m+1,e,x,y);
	if(y<=m)return quCnt(tree[l].lc,tree[r].lc,s,m,x,y);
	return quCnt(tree[l].lc,tree[r].lc,s,m,x,m)+quCnt(tree[l].rc,tree[r].rc,m+1,e,m+1,y);
}

LL quSum(int l,int r,int s,int e,int x,int y){
	if(s==x&&e==y)return tree[r].sum-tree[l].sum;
	int m=(s+e)>>1;
	if(x>m)return quSum(tree[l].rc,tree[r].rc,m+1,e,x,y);
	if(y<=m)return quSum(tree[l].lc,tree[r].lc,s,m,x,y);
	return quSum(tree[l].lc,tree[r].lc,s,m,x,m)+quSum(tree[l].rc,tree[r].rc,m+1,e,m+1,y);
}

PMM quHash(int l,int r,int s,int e,int x,int y){
	if(s==x&&e==y){
        PMM lv = tree[l].hh, rv = tree[r].hh;
        return {rv.F-lv.F,rv.S-lv.S};
    }
	int m=(s+e)>>1;
	if(x>m)return quHash(tree[l].rc,tree[r].rc,m+1,e,x,y);
	if(y<=m)return quHash(tree[l].lc,tree[r].lc,s,m,x,y);
	PMM lv = quHash(tree[l].lc,tree[r].lc,s,m,x,m), rv = quHash(tree[l].rc,tree[r].rc,m+1,e,m+1,y);
    return {rv.F+lv.F,rv.S+lv.S};
}

int main(){
    DRII(n,qn);
    REP(i,n){
		RI(d[i]);
		if(SZ(p[d[i]]))e[i]=p[d[i]].back()+1;
		else e[i]=0;
		p[d[i]].PB(i);
	}
	REP(i,n){
		up(root[i+1],root[i],0,n,e[i],d[i],{mint(d[i])*d[i],(mint(d[i])*d[i])*d[i]});
	}
    REP(i,qn){
        DRIII(a,b, dd);
        mint dist = dd;
        if(a>=b){puts("Yes");continue;}
		LL kCnt = quCnt(root[a-1],root[b],0,n,0,a-1);//num distinct?
        mint k = kCnt;
        mint dSum = quSum(root[a-1],root[b],0,n,0,a-1);//distinct sum?
        //printf("%lld %u\n",kCnt,dSum.x);
        mint s = dSum - dist*(((kCnt*(kCnt-1)/2))%MOD);//starting value?
        s/=k;
        PMM distH = quHash(root[a-1],root[b],0,n,0,a-1);
        //printf("%u %u %u\n",s.x, distH.F.x,distH.S.x);
        mint expectSq = s*s*k + s*dist*k*(k-1)+k*(k-1)*(k*2-1)/6*dist*dist;
        
        //a--; b--;
        if(expectSq.x != distH.F.x){
            puts("No");
        }
        else puts("Yes");
    }
}