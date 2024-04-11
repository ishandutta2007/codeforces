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
#define MAX 100010
int n,m,k;
vector<PI> d[MAX];
bool cz[MAX],cz2[MAX];
int il;
int odl[MAX];
priority_queue<PI> kol;
main(){
	make(n);make(m);make(k);
	R(i,m){
		int a,b,c;
		make(a);a--;
		make(b);b--;
		make(c);
		d[a].PB(MP(b,c));
		d[b].PB(MP(a,c));
	}
	R(i,n)odl[i] = 1e9+1;
	odl[0] = 0;
	R(i,k){
		int a,b;
		make(a);a--;
		make(b);
		if(odl[a] != 1e9+1){
			il ++;
			odl[a] = min(odl[a],b);
		}else{
			odl[a] = b;
			cz2[a] = 1;
		}
	}
	R(i,n){
		if(odl[i] != 1e9+1)
			kol.push(MP(-odl[i],i));
	}
	kol.push(MP(0,0));
	while(!kol.empty()){
		PI ak = kol.top();kol.pop();
		if(odl[ak.SE] != -ak.FI)continue;
		R(i,d[ak.SE].size()){
			int pom = d[ak.SE][i].FI;
			int od = d[ak.SE][i].SE - ak.FI;
			if(odl[pom] >= od)cz[pom] = 1;
			if(odl[pom] > od){
				odl[pom] = od;
				kol.push(MP(-od,pom));
			}
		}
	}
	R(i,n)if(cz[i] && cz2[i])il++;
	printf("%d\n",il);
}