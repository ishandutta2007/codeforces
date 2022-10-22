#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=210000;
int id[N],d[N],n,to[N];
int cmp(int a,int b)
{
	return d[a]>d[b];
}
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,cmp);
	for(int i=2;i<=n;i++) printf("%d %d\n",id[i-1]*2-1,id[i]*2-1);
	int tot=n;
	for(int i=1;i<=n;i++) to[i]=id[i]*2-1;
	for(int i=1;i<=n;i++)
	{
		if(tot<=i+d[id[i]]-1) to[++tot]=id[i]*2,printf("%d %d\n",to[tot],to[tot-1]);
		else printf("%d %d\n",id[i]*2,to[i+d[id[i]]-1]);
	}
	return 0;
}