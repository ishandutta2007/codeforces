#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
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
#define MAX 5001
#define MAX2 40000
int n,m,t[MAX],b[MAX],tpom[MAX];
vector<int> p;
set<int> s;
int licz(int a){
	int wyn = 0;
	for(int i=0;p[i]*p[i]<=a;i++){
		while(a % p[i] == 0){
			if(p[i] < 0)
				wyn--;
			else
				wyn++;
			a/=p[i];
			if(a < 0)a=-a;
		}
	}
	if(a!=1){
		if(s.count(a))
			wyn--;
		else
			wyn++;
	}
	return wyn;
}
bool cz[MAX2];
main(){
	make(n);make(m);
	R(i,n)make(t[i]);
	R(i,m)make(b[i]);
	sort(b,b+m);
	int jj = 0;
	F(i,2,MAX2){
		if(cz[i] == 0){
			if(jj != m && i == b[jj]){
				jj++;
				p.PB(-i);
			}else
				p.PB(i);
			for(int j=0;i*j<MAX2;j++)
				cz[i*j] = 1;
		}
	}
	R(i,m)s.insert(b[i]);
	int nwd = 0,wyn=0;
	R(i,n){
		wyn+=licz(t[i]);
		nwd = __gcd(t[i],nwd);
		tpom[i] = licz(nwd);
	//	printf("%d ",tpom[i]);
	}
//	printf("\n");
	//printf("%d\n",wyn);
	int pom = 0;
	R(i,n){
		if(tpom[n-i-1] < pom){
			wyn -= (n-i) * (tpom[n-i-1]-pom);
			pom = tpom[n-i-1];
		}
		
		//printf("(%d,%d) ",pom,wyn);
	}
	//puts("");
	printf("%d\n",wyn);
}