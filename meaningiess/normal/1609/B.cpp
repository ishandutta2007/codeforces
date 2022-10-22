#include<bits/stdc++.h>
#define ll long long
using namespace std;
char a[100010],tp[2];int u[100010],ans;
int main()
{
	int n,q,i,j;cin>>n>>q;
	cin>>a+1;
	for (i=1;i<=n-2;i++) if (a[i]=='a' && a[i+1]=='b' && a[i+2]=='c') ans++,u[i]=1;
	while (q--)
	{
		scanf("%d%s",&i,tp);
		a[i]=tp[0];
		for (j=max(1,i-2);j<=min(n-2,i);j++) if (a[j]=='a' && a[j+1]=='b' && a[j+2]=='c')
		{
			ans+=1-u[j];u[j]=1;
		}
		else ans-=u[j],u[j]=0;
		cout<<ans<<endl;
	}
}