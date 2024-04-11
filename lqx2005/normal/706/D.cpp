#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200000,Log=40;
int ch[maxn*Log+5][2],tot=0;
int cnt[maxn*Log+5],p2[maxn+5];
int one(int num,int k)
{
	if(num&p2[k]) return 1;
	return 0;
}
void ins(int num)
{
	int root=0;
	for(int i=Log;i>=0;i--)
	{
		int to=one(num,i);
		if(!ch[root][to]) ch[root][to]=++tot;
		root=ch[root][to];
		cnt[root]++;
	}
	return;
}
void era(int num)
{
	int root=0;
	for(int i=Log;i>=0;i--)
	{
		int to=one(num,i);
		cnt[ch[root][to]]--;
		if(!cnt[ch[root][to]])
		{
			ch[root][to]=0; 
			return;
		}
		root=ch[root][to];
	}	
	return;
}
int que(int num)
{
	int ans=0;
	int root=0;
	for(int i=Log;i>=0;i--)
	{
		int to=one(num,i);
		if(ch[root][to^1]) to^=1;
		root=ch[root][to];
		ans|=p2[i]*to;
	}
	return (ans^num);
}
int n;
signed main()
{
	p2[0]=1;
	for(int i=1;i<=Log;i++) p2[i]=p2[i-1]*2;
	scanf("%d",&n);
	ins(0);
	char op[2];
	int num;
	for(int i=1;i<=n;i++) 
	{
		scanf("%s%lld",op,&num);
		if(op[0]=='+') ins(num);
		if(op[0]=='-') era(num);
		if(op[0]=='?') printf("%lld\n",que(num));
	}
	return 0;
}