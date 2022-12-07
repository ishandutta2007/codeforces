#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
int n,k,Q,a[100010],x;
map<int,int> M;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			if(M.count(a[i]*j)) M[a[i]*j]=min(M[a[i]*j],j);
			else M[a[i]*j]=j;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&x);
		int con=1000000000;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
				if(M.count(x-a[i]*j)) con=min(con,j+M[x-a[i]*j]);
		if(con>k) puts("-1");
		else printf("%d\n",con);
	}
	return 0;
}