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
#define MAX 1001
int n,t[MAX];
int ib;
struct blok{
	int p,k;
	int dl(){
		return p<k?k-p+1:p-k+1;
	}
	void swa(){
		swap(p,k);
	}
}b[MAX];
bool qb(blok a,blok b){
	return t[a.p] < t[b.p];
}
bool spr(){
	R(i,ib)if(b[i].p > b[i].k)return 0;
	R(i,ib-1)if(b[i].k > b[i+1].p)return 0;
	return 1;
}
int wyna[4],wynb[4];
void wys(int il){
	printf("%d\n",il);
	FD(i,il){
		printf("%d %d\n",wyna[i],wynb[i]);
	}
	exit(0);	
}
void odw(int po,int ko){
	while(ko>po){
		swap(b[po],b[ko]);
		b[po].swa();
		b[ko].swa();
		po++;
		ko--;
	}
	if(po==ko)
		b[po].swa();
}
int sum[4][MAX];
void licz(int il){
	if(spr())wys(il);
	if(il==3)return;
	R(i,ib)
		sum[il][i+1] = sum[il][i] + b[i].dl();
	R(i,ib)F(j,i,ib){
		if(i==j&&b[i].dl()==1)continue;
		wyna[il] = sum[il][i]+1;
		wynb[il] = sum[il][j+1];
		odw(i,j);
		licz(il+1);
		odw(i,j);
	}
}
main(){
	make(n);
	R(i,n){
		int pom;
		make(pom);pom--;
		t[pom] = i;
	}
	t[n]=-2;
	R(i,n){
		int ak=i;
		while(abs(t[ak]-t[ak+1])==1)ak++;
		if(ak-i==1){
			b[ib].p=i;
			b[ib].k=i;
			ib++;
			b[ib].p=ak;
			b[ib].k=ak;
			ib++;
			i=ak;
			continue;
		}
		b[ib].p=i;
		b[ib].k=ak;
		if(t[i] > t[ak])
			swap(b[ib].p,b[ib].k);
		ib++;
		i=ak;
	}
	sort(b,b+ib,qb);
	licz(0);
}