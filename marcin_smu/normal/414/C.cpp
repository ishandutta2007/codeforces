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
#define pll(A) printf("%lld\n",A)
#else
#define makel(A) scanf("%I64d",&A)
#define pll(A) printf("%I64d\n",A)
#endif
#define MAX (1<<20) 
int n,m;
int gl[MAX*2];
LL wyn = 0;
LL row[21],inv[21],all[21];
vector<int> d[MAX*2];
void licz_inv(int nr){
	int i=0,j=0;
	int k = d[nr*2].size();
	vector<int>& a = d[nr*2];
	vector<int>& b = d[nr*2+1];
	gl[nr] = gl[nr*2] + 1;
	int pom = 0,ost = -1;
	while(i < k || j < k){
		if(j == k || (i!=k && a[i] <= b[j] )){
			d[nr].PB(a[i]);
			if(ost == a[i])
				pom ++;
			else{
				ost = a[i];
				pom = 1;
			}
			i++;
		}else{
			d[nr].PB(b[j]);
			if(b[j] == ost)
				row[gl[nr]] += pom;
			inv[gl[nr]] += k-i;
			j++;
		}
	}
}
main(){
	int nn;
	make(nn);
	n = (1<<nn);
	R(i,n){
		int pom;make(pom);
		d[i+n].PB(pom);
		gl[i] = 0;
	}
	for(int i=n-1;i>0;i--){
		licz_inv(i);
	}
	
	F(i,1,nn+1){
		wyn += inv[i];
		all[i] = (1ll<<(nn+i-2)) - row[i];
	}
	make(m);
	R(i,m){
		int pom;
		make(pom);
		F(i,1,pom+1){
			wyn -= inv[i];
			inv[i] = all[i] - inv[i];
			wyn += inv[i];
		}
		pll(wyn);
	}
}