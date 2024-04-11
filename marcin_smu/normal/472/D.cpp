#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PI;
typedef long long LL;
typedef double D;
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define R(I,N) for(int I=0;I<N;I++)
#define F(I,A,B) for(int I=A;I<B;I++)
#define FD(I,N) for(int I=N-1;I>=0;I--)
#define make(A) scanf("%d",&A)
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld ",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
#endif
template<typename C> void ma(C& a,C b){if(a<b)a=b;}
template<typename C> void mi(C& a,C b){if(a>b)a=b;}
int n;
#define MAX 2001
vector<pair<int,PI> > d2;
int f[MAX],t[MAX][MAX];
void nie(){
	puts("NO");
	exit(0);
}
int find(int a){
	return f[a] == a?a:f[a] = find(f[a]);
}
bool uni(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)return 0;
	f[a] = b;
	return 1;
}
vector<PI> d[MAX];
int gl;
void dfs(int nr,int dl,int oj){
	if(t[gl][nr] != dl)nie();
	R(i,d[nr].size())if(d[nr][i].FI != oj)dfs(d[nr][i].FI,dl+d[nr][i].SE,nr);
}
main(){
	make(n);
	R(i,n)f[i]=i;
	R(i,n)R(j,n){
		make(t[i][j]);
		if(i != j){
			if(t[i][j] == 0)nie();
			d2.PB(MP(t[i][j],MP(i,j)));
		}
	}
	sort(d2.begin(),d2.end());
	R(i,d2.size()){
		if(uni(d2[i].SE.FI,d2[i].SE.SE)){
			d[d2[i].SE.FI].PB(MP(d2[i].SE.SE,d2[i].FI));
			d[d2[i].SE.SE].PB(MP(d2[i].SE.FI,d2[i].FI));
		}
	}
	R(i,n){
		gl = i;
		dfs(i,0,-1);
	}
	puts("YES");
}