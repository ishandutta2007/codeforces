#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,cnt[2][2],X[N],Y[N],st[N];
bool slv()
{
	cnt[0][0]=cnt[1][1]=cnt[0][1]=cnt[1][0]=0;
	for(int i=1;i<=n;++i) ++cnt[X[i]&1][Y[i]&1];
	if(cnt[0][0]+cnt[1][1] && cnt[0][1]+cnt[1][0])
	{
		for(int i=1;i<=n;++i)
			if((X[i]&1)^(Y[i]&1)) st[++st[0]]=i;
	}
	else if(cnt[0][0] && cnt[1][1])
	{
		for(int i=1;i<=n;++i)
			if(X[i]&1 && Y[i]&1) st[++st[0]]=i;
	}
	else if(cnt[0][1] && cnt[1][0])
	{
		for(int i=1;i<=n;++i)
			if(X[i]&1 && !(Y[i]&1)) st[++st[0]]=i;
	}if(!st[0]) return 0;printf("%d\n",st[0]);
	for(int i=1;i<=st[0];++i)
		printf("%d ",st[i]);return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d %d",&X[i],&Y[i]);
	while(1)
	{
		if(slv()) break;
		for(int i=1;i<=n;++i) X[i]>>=1,Y[i]>>=1;
	}return 0;
}