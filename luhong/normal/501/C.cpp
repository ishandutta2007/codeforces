#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,s[101000],d[101000];int q[1010000],H=0,T=0;
int cnt[100000][2],K;
void ins(int u,int v){if(d[u]==0)return;K++;cnt[K][0]=u;cnt[K][1]=v;}
int main()
{
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d%d",&d[i],&s[i]);
	for(int i=0;i<n;i++)
		if(d[i]==1){ins(i,s[i]);d[i]=0;q[T++]=s[i];s[s[i]]^=i;d[s[i]]--;}
	while(H<T)
	{
		int i=q[H++];if(d[i]==1){ins(i,s[i]);d[i]=0;s[s[i]]^=i;if((--d[s[i]])==1)q[T++]=s[i];}
	}
	printf("%d\n",K);
	for(int i=1;i<=K;i++)printf("%d %d\n",cnt[i][0],cnt[i][1]);
	return 0;
}