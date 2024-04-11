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
#ifdef LOCAL
#define makel(A) scanf("%lld",&A)
#define pll(A) printf("%lld ",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d ",A)
#endif
#define MAX 201
int n,kk,a[MAX];
main(){
	make(n);
	make(kk);
	R(i,n)make(a[i]);
	int wyn = -2000;
	R(i,n)F(j,i,n){
		vector<int> b,c;
		int sum = 0;
		R(k,n){
			if(i<=k && k<=j){
				b.PB(a[k]);
				sum += a[k];
			}else
				c.PB(a[k]);
		}
		sort(b.begin(),b.end());
		sort(c.begin(),c.end());
		R(k,kk){
			if(c.size() <= k || b.size() <= k)continue;
			if(b[k] < c[c.size() - k -1]){
				sum -= b[k];
				sum += c[c.size() - k -1];
			}
		}
		if(sum > wyn)wyn = sum;
	}
	printf("%d\n",wyn);
}