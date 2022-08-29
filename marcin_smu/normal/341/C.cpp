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
#define MAX 2001
const int P = 1000 * 1000 * 1000 +7;
int n;
LL t[MAX][MAX];
bool cz[MAX];
main(){
	make(n);
	t[0][0]=1;
	F(dl,1,n+1){
		t[dl][0] = t[dl-1][0]*dl%P;
		t[dl][1] = t[dl-1][0]*(dl-1)%P;
		F(in,2,dl+1){
			t[dl][in] = t[dl-1][in-2] * (in-1) + t[dl-1][in-1] * (dl-in);
			t[dl][in]%=P;
		}
	}
	int il=n;
	R(i,n){
		int pom;make(pom);
		if(pom != -1){
			il--;
			cz[i]=1;
			cz[pom-1]=1;
		}
	}
	int wyn=0;
	R(i,n)if(!cz[i])wyn++;
	printf("%d\n",int(t[il][wyn]));
}