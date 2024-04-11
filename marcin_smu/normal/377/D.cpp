#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
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
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
//#define makel(A) scanf("%lld",&A)
//#define pll(A) printf("%lld ",A)
#define MAX (1<<20)
struct odc{
	int a,b,y;
	bool x;
	void ust(int a,int b,int y,bool x){
		this->a=a;
		this->b=b;
		this->y=y;
		this->x=x;
	};
}t[MAX];
bool operator<(odc a,odc b){
	if(a.y!=b.y)return a.y < b.y;
	return a.x<b.x;
}
int nn,pp,kp,gl;
int dp[MAX*2],il[MAX*2];
void add(int nr=1,int pk=0,int kk=nn-1){
	if(pp > kk || pk > kp) return;
	if(pp <= pk && kk <= kp){
		if(pk == kk){
			dp[nr] += gl;
		}else{
			il[nr] += gl;
			dp[nr] = il[nr] + max(dp[nr*2],dp[nr*2+1]);
		}
		return;
	}
	add(nr*2,pk,(pk+kk)/2);
	add(nr*2+1,(pk+kk)/2+1,kk);
	dp[nr] = il[nr] + max(dp[nr*2],dp[nr*2+1]);
}
int n;
int l[MAX],v[MAX],r[MAX];
main(){
	make(n);
	nn=(1<<19);//1;while(nn<=n)nn*=2;
	R(i,2*nn){
		il[i]=0;
		dp[i]=0;
	}
	R(_,n){
		int a,i,b;
		make(a);make(i);make(b);
		t[_*2].ust(i,b,a,0);
		t[_*2+1].ust(i,b,i,1);
		l[_] = a;
		v[_] = i;
		r[_] = b;
	}
	sort(t,t+2*n);
	int wyn=0,wynx,wyny;
	R(i,n*2){
		if(t[i].x){
			pp = t[i].a;
			kp = t[i].b;
			gl = -1;
			add();
		}else{
			pp = t[i].a;
			kp = t[i].b;
			gl = 1;
			add();
			if(wyn < dp[1]){
				wyn = dp[1];
				int gd=1;
				int ak = 0;
				wynx = t[i].y;
				while(gd<nn){
					ak-=dp[gd];
					gd*=2;
					if(dp[gd+1] > dp[gd])gd++;
				}
				wyny=gd-nn;
			}
		}
	}
	printf("%d\n",wyn);
	R(i,n){
		if(l[i] <= wynx && wynx <= v[i] && v[i] <= wyny && wyny <= r[i])
			printf("%d ",i+1);
	}
	puts("");
}