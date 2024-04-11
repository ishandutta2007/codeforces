#include<bits/stdc++.h>
#define P 1000000007
#define ll long long
using namespace std;
int n,L,m,a[1000005],f[100005],x;
struct Mr
{
	int M[102][102];
}A,B;
Mr operator+(Mr A,Mr B)
{
	Mr ans;
	memset(ans.M,0,sizeof ans.M);
	for (int i=0;i<m;i++)
	for (int j=0;j<m;j++)
		ans.M[i][j]=(A.M[i][j]+B.M[i][j])%P;
	return ans;
}
Mr operator*(Mr A,Mr B)
{
	Mr ans;
	memset(ans.M,0,sizeof ans.M);
	for (int k=0;k<m;k++)
	for (int i=0;i<m;i++)
	for (int j=0;j<m;j++)
		ans.M[i][j]=(ans.M[i][j]+(ll)A.M[i][k]*B.M[k][j]%P)%P;
	return ans;
}
void pr(Mr a)
{
	puts("--------");
	for (int i=0;i<m;i++,puts(""))
		for (int j=0;j<m;j++)
		{
			printf("%d ",a.M[i][j]);
		}
}
Mr pw(Mr A,int k)
{
	Mr ans;
	memset(ans.M,0,sizeof ans.M);
	//pr(A);
	for (int i=0;i<m;i++)
		ans.M[i][i]=1;
	for (;k;k>>=1,A=A*A)
		if (k&1) ans=ans*A;
	//pr(A);
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&L,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		//x=0;
		A.M[0][x]++;
	}
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),f[a[i]%m]++;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			B.M[i][j]=f[(j-i+m)%m];
	A=A*pw(B,L-2);
	//pr(A);
	memset(f,0,sizeof f);
	for (int i=1;i<=n;i++)
		scanf("%d",&x),f[(a[i]+x)%m]++;
	for (int i=0;i<m;i++)
		for (int j=0;j<m;j++)
			B.M[i][j]=f[(j-i+m)%m];
	A=A*B;
	printf("%d\n",A.M[0][0]);
}