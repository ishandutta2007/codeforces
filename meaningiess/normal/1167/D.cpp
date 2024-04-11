#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
char a[N];int t[2][N],tp[2],e[N];
int main()
{
	int n,i,ans=0;cin>>n;cin>>a+1;
	for (i=1;i<=n;i++)
	{
		if (a[i]=='(')
		{
			if (tp[0]<tp[1]) t[0][++tp[0]]=i,e[i]=0;
			else t[1][++tp[1]]=i,e[i]=1;
		}
		else
		{
			if (t[0][tp[0]]>t[1][tp[1]]) tp[0]--,e[i]=0;
			else tp[1]--,e[i]=1;
		}
	}
	for (i=1;i<=n;i++) cout<<e[i];
}