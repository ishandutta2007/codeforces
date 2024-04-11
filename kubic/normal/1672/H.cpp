#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int n,m,b[2][N];char a[N];
int main()
{
	scanf("%d %d %s",&n,&m,a+1);
	for(int i=1;i<n;++i) if(a[i]==a[i+1]) b[a[i]-48][i]=1;
	for(int i=1;i<n;++i) b[0][i]+=b[0][i-1],b[1][i]+=b[1][i-1];
	for(int i=1,l,r,t[2];i<=m;++i)
	{
		scanf("%d %d",&l,&r);
		t[0]=b[0][r-1]-b[0][l-1];t[1]=b[1][r-1]-b[1][l-1];
		printf("%d\n",max(t[0],t[1])+1);
	}return 0;
}