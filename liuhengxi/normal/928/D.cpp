#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int to[N][26],n,ans,cnt=1,tot[N],ch[N];
char s[N],t[N];
int add(char *s,int n)
{
	int j=0,st=0;
	if(n==0)return 0;
	++tot[0];
	F(i,0,n)
	{
		int x=s[i]-'a';
		if(!to[j][x])
		{
			++ch[j];
			if(!st)st=ch[j]==1?1:2;
			to[j][x]=cnt++;
		}
		++tot[j=to[j][x]];
	}
	if(ch[j]&&!st)st=3;
	j=0;
	if(st==0)
	{
		--tot[0];
		F(i,0,n)
		{
			int x=s[i]-'a';
			--tot[j=to[j][x]];
		}
		j=0;
		F(i,0,n)
		{
			int x=s[i]-'a';
			j=to[j][x];
			if(tot[j]==1)return i+2<n?i+2:n;
		}
	}
	if(st==1)
	{
		int save=-2;
		F(i,0,n)
		{
			int x=s[i]-'a';
			j=to[j][x];
			if(tot[j]==2)++save;
		}
		if(save<0)save=0;
		return n-save;
	}
	return n;
}
int main()
{
	while(gets(s)!=NULL)
	{
		for(int i=0;s[i];++i)
		{
			if(s[i]<'a'||s[i]>'z')ans+=add(t,n)+1,n=0;
			else t[n++]=s[i];
		}
		if(n)ans+=add(t,n),n=0;
		++ans;
	}
	printf("%d\n",ans);
	return 0;
}