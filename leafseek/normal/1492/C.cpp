#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxLen=200000+5,Sigma=26,Err=(MaxLen<<1);
inline int CharIndex(const register char ch)
	{return (ch-'a'+1);}
char strA[MaxLen],strB[MaxLen];
int nextA[MaxLen][Sigma+1],nextB[MaxLen][Sigma+1],dpnext[MaxLen];
int prevA[MaxLen][Sigma+1],prevB[MaxLen][Sigma+1],dpprev[MaxLen];
inline void DynamicProgramming(const register int lenA,const register int lenB)
{
	dpnext[0]=0;
	rep(i,1,lenB)
		if(dpnext[i-1]+1<=lenA) 
			dpnext[i]=nextA[dpnext[i-1]+1][CharIndex(strB[i])];
	dpprev[lenB+1]=lenA+1;
	dow(i,lenB,1)
		if(dpprev[i+1]-1>=0)
			dpprev[i]=prevA[dpprev[i+1]-1][CharIndex(strB[i])];
}
int main()
{
	register int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s%s",strA+1,strB+1);
	rep(x,0,Sigma)
		nextA[n+1][x]=+Err;
	dow(i,n,1)
	{
		rep(x,0,Sigma)
			nextA[i][x]=nextA[i+1][x];
		nextA[i][CharIndex(strA[i])]=i;
	}
	rep(x,0,Sigma)
		nextB[m+1][x]=+Err;
	dow(i,m,1)
	{
		rep(x,0,Sigma)
			nextB[i][x]=nextB[i+1][x];
		nextB[i][CharIndex(strB[i])]=i;
	}
	rep(x,0,Sigma)
		prevA[1-1][x]=-Err;
	rep(i,1,n)
	{
		rep(x,0,Sigma)
			prevA[i][x]=prevA[i-1][x];
		prevA[i][CharIndex(strA[i])]=i;
	}
	rep(x,0,Sigma)
		prevB[1-1][x]=-Err;
	rep(i,1,m)
	{
		rep(x,0,Sigma)
			prevB[i][x]=prevB[i-1][x];
		prevB[i][CharIndex(strB[i])]=i;
	}
	DynamicProgramming(n,m);
	register int Max=0;
	rep(i,1,m-1)
		Max=max(Max,dpprev[i+1]-dpnext[i]);
	printf("%d\n",Max);
	return 0;
}