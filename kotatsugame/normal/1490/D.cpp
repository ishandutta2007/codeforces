#include<cstdio>
using namespace std;
int T,N;
int A[100];
int dep[100];
void rec(int l,int r,int d)
{
	if(l==r)return;
	int mx=l;
	for(int i=l;i<r;i++)if(A[mx]<A[i])mx=i;
	dep[mx]=d;
	rec(l,mx,d+1);
	rec(mx+1,r,d+1);
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		rec(0,N,0);
		for(int i=0;i<N;i++)printf("%d%c",dep[i],i+1==N?10:32);
	}
}