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
#define MAX (1<<18)+1
int n,nn,m;
int t[MAX];
main(){
	make(n);make(m);
	nn=(1<<n);
	R(i,nn)
		make(t[nn+i]);
	int pom = nn;
	bool co=1;
	while(pom){
		if(co){
			FD(i,pom)
				t[i] = (t[i*2] | t[i*2+1]);
		}else
			FD(i,pom)
				t[i] = (t[i*2] ^ t[i*2+1]);
		co=!co;
		pom/=2;
	}
	/*R(i,nn*2){
		printf("%d\n",t[i]);
	}*/
	R(i,m){
		int a,b;make(a);make(b);
		t[nn+a-1] = b;
		int ak = nn+a-1;
		ak/=2;
		bool co=1;
		while(ak){
			if(co)
				t[ak] = (t[ak*2] | t[ak*2+1]);
			else
				t[ak] = (t[ak*2] ^ t[ak*2+1]);
			ak/=2;
			co=!co;
		}
		printf("%d\n",t[1]);
	}
}