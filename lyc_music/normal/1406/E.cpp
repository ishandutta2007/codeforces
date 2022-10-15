#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int nmysl=114514;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
int n,p[N],cnt=0,ans=1,mul[233];
bool vis[N];
int A(int x)
{
	printf("A %d\n",x);
	fflush(stdout);
	int ret=read();
	return ret;
}
int B(int x)
{
	printf("B %d\n",x);
	fflush(stdout);
	int ret=read();
	return ret;
}
void C(int x)
{
	printf("C %d\n",x);
	fflush(stdout);
}

signed main()
{
	mul[0]=1;
	n=read();
	if (n==1) return C(1),0;
	memset(vis,0,sizeof(vis));
	for (int i=2;i<=n;i++)
	{
		if (!vis[i]) p[++cnt]=i;
		for (int j=1;j<=cnt;j++)
		{
			if (i*p[j]>n) break;
			vis[i*p[j]]=1;
			if (i%p[j]==0) break;
		}
	}
	int s=sqrt(n),m=cnt,num;
	for (int i=1;i<=m;i++)
	if (p[i]>s)
	{
		num=i-1;
		break;
	}
	for (int i=1;i<=num;i++)
	{
		int nmsl=B(p[i]);
		int f=A(p[i]);
		if (f)
		{
			int l=1,r=0;
			while (mul[r]*p[i]<=n) r++,mul[r]=mul[r-1]*p[i];
			while (l<=r)
			{
				int mid=(l+r)/2;
				if (A(mul[mid])) l=mid+1;
							else r=mid-1;
			}
			ans*=mul[r];
		}
	}
	int now=num,pre=num,lst=A(1),len=sqrt(m-num),tot=0;
	while (now<m)
	{
		now++;
		tot+=B(p[now]);
		if (now-pre>=len||now==m)
		{
			int tmp=A(1);
			if (lst-tmp!=tot)
			for (int i=pre+1;i<=now;i++)
			if (A(p[i]))
			return C(ans*p[i]),0;
			lst=tmp;
			pre=now;
			tot=0;
		}
	}
	C(ans);

	return 0;
}