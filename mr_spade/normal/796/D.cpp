#pragma GCC diagnostic error "-std=gnu++11"
#include<cstdio>
#include<queue>
using std::pair;
using std::queue;
const int N(3e5+5);
int n,k,d;
int v[N<<1],first[N],next[N<<1];
bool book[N],shutdown[N];
queue<pair<int,int>>Q;
inline int read()
{
	int sum(0);
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		sum=(sum<<3)+(sum<<1)+x-'0';
	return sum;
}
inline void write(int x)
{
	if(x>=10)
		write(x/10);
	putchar(x%10+'0');
	return;
}
inline int f(int x)
{
	if(x>=n-1)
		x-=n-1;
	if(!x)
		x=n-1;
	return x;
}
signed main()
{
	int i,go,cnt(0);
	n=read();k=read();d=read();
	for(i=1;i<=k;i++)
		Q.push({read(),0});
	for(i=1;i<n;i++)
	{
		v[i+n-1]=read();v[i]=read();
		next[i]=first[v[i+n-1]];
		first[v[i+n-1]]=i;
		next[i+n-1]=first[v[i]];
		first[v[i]]=i+n-1;
	}
	while(!Q.empty())
	{
		while(!Q.empty()&&book[Q.front().first])
			Q.pop();
		if(Q.empty())
			break;
		book[Q.front().first]=1;
		for(go=first[Q.front().first];go;go=next[go])
			if(v[go]!=Q.front().second)
			{
				if(book[v[go]])
					shutdown[f(go)]=1;
				else
					Q.push({v[go],Q.front().first});
			}
	}
	for(i=1;i<n;i++)
		if(shutdown[i])
			cnt++;
	write(cnt);putchar('\n');
	for(i=1;i<n;i++)
		if(shutdown[i])
			write(i),putchar(' ');
	return putchar('\n'),0;
}