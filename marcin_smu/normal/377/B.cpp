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
#define MAX 200001
int n,m,lim;
PI k[MAX];
struct stu{
	int first;
	int second;
	int nr;
}s[MAX];
bool licz(int il){
	int kos =0;
	priority_queue<int> kol;
	int j=0;
	for(int i=0;i<n;i+=il){
		while(j<m && s[j].FI>=k[i].FI){
			kol.push(-s[j].SE);
			j++;
		}
		if(kol.empty())return 0;
		kos -= kol.top();
		kol.pop();
		if(kos > lim)return 0;
	}
	return 1;
}
int wyn[MAX];
void licz2(int il){
	int kos =0;
	priority_queue<PI> kol;
	int j=0;
	for(int i=0;i<n;i+=il){
		while(j<m && s[j].FI>=k[i].FI){
			kol.push(MP(-s[j].SE,s[j].nr));
			j++;
		}
		F(j,i,min(i+il,n))wyn[k[j].SE] = kol.top().SE;
		kol.pop();
	}
}
bool q(stu a,stu b){
	return a.FI > b.FI;
}
bool q2(PI a,PI b){
	return a.FI > b.FI;
}
main(){
	make(m);
	make(n);
	make(lim);
	R(i,n)make(k[i].FI);
	R(i,n)k[i].SE = i;
	sort(k,k+n,q2);
	R(i,m)make(s[i].FI);
	R(i,m)make(s[i].SE);
	R(i,m)s[i].nr = i;
	sort(s,s+m,q);
	int po=0,ko=n+1;
	while(po+1!=ko){
		int me = (po+ko)/2;
		if(licz(me))
			ko = me;
		else
			po = me;
	}
	if(ko==n+1){
		printf("NO\n");
	}else{
		printf("YES\n");
		licz2(ko);
		R(i,n)printf("%d ",wyn[i]+1);
		puts("");
	}
}