#include<cstdio>
#include<cstring>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,t[5005],a[5005];
inline void add(int x,int y) {for(;x<=n;x+=(x&(-x))) t[x]+=y;}
inline int que(int x) {int r=0;for(;x;x-=(x&(-x))) r+=t[x];return r;}
int main()
{
	read(n);int res=0,cnt=0,mx=0;
	for(int i=1;i<=n;i++) read(a[i]),a[i]++;
	for(int i=1;i<=n;i++) res+=i-que(a[i]-1)-1,add(a[i],1);
	for(int i=1;i<=n;i++)
	{
		memset(t,0,sizeof(t));
		for(int j=i+1;j<=n;j++)
		{
			int A=que(a[i])-que(n)+que(a[i]-1),B=que(n)-que(a[j])-que(a[j]-1),c=A+B;
			if(a[i]>a[j]) c++;else c--;
			if(mx<c) mx=c,cnt=1;else if(mx==c) cnt++;
			add(a[j],1);
		}
	}
	return printf("%d %d\n",res-mx,cnt),0;
}