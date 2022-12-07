#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1010;
int n,a[MAXN],b[MAXN],tot,ans=1000000000,con;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<n;i++)
	{
		tot=0,con=-1000000000;
		for(int j=1;j<=n;j++)
			if(i!=j) b[++tot]=a[j];
		//for(int j=1;j<=tot;j++) cout<<b[j]<<endl;
		//cout<<"____________"<<endl;
		for(int j=1;j<tot;j++)
			con=max(con,b[j+1]-b[j]);
		ans=min(ans,con);
	}
	printf("%d\n",ans);
	return 0;
}