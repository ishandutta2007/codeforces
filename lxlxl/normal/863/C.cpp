#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 1100;

ll k;
int a,b;
int A[4][4],B[4][4];
ll ca,cb;

ll c[maxn][2];
int v[4][4];

void mark(int x,int y) 
{
	if(x==y) return;
	if(x==1)
	{
		if(y==2) cb++;
		else ca++;
	}
	else if(x==2)
	{
		if(y==1) ca++;
		else cb++;
	}
	else
	{
		if(y==1) cb++;
		else ca++;
	}
}

int main()
{
	scanf("%I64d%d%d",&k,&a,&b); mark(a,b);
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) scanf("%d",&A[i][j]);
	for(int i=1;i<=3;i++) for(int j=1;j<=3;j++) scanf("%d",&B[i][j]);
	
	v[a][b]=1; c[1][0]=0,c[1][1]=0;
	int i;
	for(i=2;i<=k;i++)
	{
		c[i][0]=ca,c[i][1]=cb;
		int ta=A[a][b],tb=B[a][b];
		a=ta,b=tb;
		if(v[a][b]) break;
		mark(a,b); v[a][b]=i;
	}
	if(i==k+1) printf("%I64d %I64d\n",ca,cb);
	else
	{
		k=(k-i+1);
		ca=ca+(ca-c[v[a][b]][0])*(k/(ll)(i-v[a][b]));
		cb=cb+(cb-c[v[a][b]][1])*(k/(ll)(i-v[a][b]));
		k%=(ll)(i-v[a][b]);
		for(i=1;i<=k;i++)
		{
			mark(a,b);
			int ta=A[a][b],tb=B[a][b];
			a=ta,b=tb;
		}
		printf("%I64d %I64d\n",ca,cb);
	}
	
	return 0;
}