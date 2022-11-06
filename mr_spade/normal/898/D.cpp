#include<cstdio>
#include<algorithm>
const int N(2e5+5);
int n,m,k,head,tail,ans,cnt;
int a[N];
bool del[N];
inline int read()
{
	int res(0);
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		res=(res<<3)+(res<<1)+x-'0';
	return res;
}
signed main()
{
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	if(k<=1)
		return printf("%d\n",n),0;
	std::sort(a+1,a+n+1);
	head=tail=1;cnt=0;
	while(head<n)
	{
		while(tail<=n&&a[tail]-a[head]+1<=m&&cnt<k-1)
			tail++,cnt++;
		while(tail<=n&&a[tail]-a[head]+1<=m)
			del[tail]=1,tail++,ans++;
		head++;cnt--;
		while(head<=n&&del[head])
			head++;
	}
	printf("%d\n",ans);
	return 0;
}