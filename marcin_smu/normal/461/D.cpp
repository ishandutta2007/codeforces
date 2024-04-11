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
const int P = 1e9 + 7;
#define MAX 100100
int n,k,kol[MAX];
int il;
vector<PI > d[MAX];
bool xxx = 0;
void dfs(int nr){
	R(i,d[nr].size()){
		int ak = d[nr][i].FI;
		if(kol[ak] == -1){
			kol[ak] = (kol[nr] ^ d[nr][i].SE);
			dfs(ak);
		}
		if(kol[ak] != (kol[nr] ^ d[nr][i].SE))
			xxx = 1;
	}
}
void tr(int a,int b,int c){
	int aa = b-a;
	int bb = b+a;
	if(aa < n && aa>=0 && bb < n && bb>=0){
		bb+=2;
		d[aa].PB(MP(bb,c));
		d[bb].PB(MP(aa,c));
	}
}
main(){
	make(n);
	make(k);
	il = n;
	R(i,n+2)kol[i] = -1;
	R(i,k){
		int a,b;
		char z;
		scanf("%d%d %c",&a,&b,&z);a--;b--;
		int c = (z == 'o');
		
		tr(a,b,c);
		swap(a,b);
		tr(a,b,c);
		a = n-a-1;
		b = n-b-1;
		tr(a,b,c);
		swap(a,b);
		tr(a,b,c);
		
	}
	kol[0] = kol[1] = 0;
	dfs(0);dfs(1);
	int wyn = 1;
	F(i,2,n+2){
		if(kol[i] == -1){
			kol[i] = 0;
			wyn*=2;
			if(wyn >= P)wyn -= P;
			dfs(i);
		}
	}
	if(xxx)
		puts("0");
	else
		printf("%d\n",wyn);
}