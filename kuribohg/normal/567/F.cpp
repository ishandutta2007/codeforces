#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,k;
LL f[36][71][71];
struct Node
{
	int x,y,op;
}A[110];
int L,R,X,Y;
int val(int i)
{
	if(L<=i&&i<=R) return 2;
	if(i==X||i==Y) return 1;
	return 0;
}
bool valid(int i)
{
	if(val(A[i].x)!=1&&val(A[i].y)!=1) return true;
	if(A[i].op==1) return val(A[i].x)>=val(A[i].y);
	else if(A[i].op==2) return val(A[i].x)<=val(A[i].y);
	else if(A[i].op==3) return val(A[i].x)>val(A[i].y);
	else if(A[i].op==4) return val(A[i].x)<val(A[i].y);
	else return val(A[i].x)==val(A[i].y);
}
bool Valid()
{
	for(int i=1;i<=k;i++)
		if(!valid(i)) return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		int x,y;
		char op[10];
		scanf("%d%s%d",&x,op,&y);
		if(op[0]=='>'&&op[1]=='=') A[i].op=1;
		else if(op[0]=='<'&&op[1]=='=') A[i].op=2;
		else if(op[0]=='>') A[i].op=3;
		else if(op[0]=='<') A[i].op=4;
		else if(op[0]=='=') A[i].op=5;
		A[i].x=x,A[i].y=y;
	}
	for(int i=1;i<n+n;i++)
	{
		L=i+1,R=i,X=i,Y=i+1;
		if(Valid()) f[n][i][i+1]=1;
	}
	for(int i=n-1;i>=1;i--)
	{
		int Len=(n-i)*2;
		for(int l=1;l<=n+n;l++)
		{
			int r=l+Len-1;
			if(r>n+n) continue;
			if(!f[i+1][l][r]) continue;
			L=l,R=r;
			if(l-1>0&&r+1<=n+n)
			{
				X=l-1,Y=r+1;
				if(Valid()) f[i][X][Y]+=f[i+1][l][r];
			}
			if(l-2>0)
			{
				X=l-1,Y=l-2;
				if(Valid()) f[i][Y][r]+=f[i+1][l][r];
			}
			if(r+2<=n+n)
			{
				X=r+1,Y=r+2;
				if(Valid()) f[i][l][Y]+=f[i+1][l][r];
			}
		}
	}
	printf("%I64d\n",f[1][1][n+n]);
	return 0;
}