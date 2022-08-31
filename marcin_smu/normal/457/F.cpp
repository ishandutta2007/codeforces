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
#define MAX 300
int cas,n,l[MAX],r[MAX],w[MAX],roz[MAX];
void licz_roz(int nr){
	if(w[nr] == -1){
		licz_roz(l[nr]);
		licz_roz(r[nr]);
		if(roz[r[nr]]&1)
			swap(l[nr],r[nr]);
		roz[nr] = 1 + roz[l[nr]] + roz[r[nr]];
	}else
		roz[nr] = 0;
}
int dp[MAX][2][3];
int ak[MAX][2][3];
inline int mima(int a,int b,bool jak){
	return ((a > b) ^ jak)?a:b;
}
inline int mima3(int a,int b,int c,bool jak){
	return mima(mima(a,b,jak),c,jak);
}
int dfs(int nr, bool kto, int pas){	
	//printf("%d %d %d\n",nr,(int)kto,pas);
	if(w[nr] != -1)return w[nr];
	if(roz[nr] == 1)
		return mima(w[l[nr]], w[r[nr]], kto^(pas==2));
	int& res = dp[nr][kto][pas];
	if(ak[nr][kto][pas] == cas)
		return res;
	ak[nr][kto][pas] = cas;
	if(pas){
		if(roz[nr]&1){
			res = dfs(nr,!kto,0);
			if(roz[l[nr]]&1){
				int pom = mima(dfs(l[nr],kto,0), dfs(r[nr], !kto, roz[l[nr]]==1&&pas==1?2:1), !kto);
				res = mima(res,pom,kto);
				pom = mima(dfs(r[nr],kto,0), dfs(l[nr], !kto, roz[r[nr]]==1&&pas==1?2:1), !kto);
				res = mima(res,pom,kto);
			}else{
				if(roz[r[nr]]){
					int pom = mima(dfs(l[nr],!kto,0), dfs(r[nr],kto,roz[l[nr]]==0&&pas==1?2:1), !kto);
					res = mima(res,pom,kto);
				}
				if(roz[l[nr]]){
					int pom = mima(dfs(r[nr],!kto,0), dfs(l[nr],kto,roz[r[nr]]==0&&pas==1?2:1), !kto);
					res = mima(res,pom,kto);
				}
			}
		}else{
			res = mima(dfs(r[nr],kto,0), dfs(l[nr],kto,roz[r[nr]]==0&&pas==1?2:1), kto);
		}
	}else{
		if(roz[nr]&1){
			if(roz[l[nr]]&1)
				res = mima(dfs(l[nr],kto,1), dfs(r[nr],kto,1), kto);
			else
				res = mima(dfs(l[nr],kto,0), dfs(r[nr],kto,0), kto);
		}else{
			int pom = mima(dfs(l[nr],kto,0), dfs(r[nr],!kto,0), !kto);
			int pom2 = mima(dfs(l[nr],!kto,1), dfs(r[nr],kto,1), !kto);
			res = mima(pom, pom2, kto);
		}
	}
	//printf("%d %d %d : %d\n",nr,(int)kto,pas,res);
	return res;
}
void test(){
	make(n);
	R(i,n){
		make(w[i]);
		if(w[i] == -1){
			make(l[i]);
			make(r[i]);
		}
	}
	licz_roz(0);
	printf("%d\n",dfs(0,0,0));
}
main(){
	int _; make(_);
	for(cas = 1; cas <= _; cas++)
		test();
}