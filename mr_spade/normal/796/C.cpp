#include<cstdio>
#include<vector>
#include<bitset>
using std::vector;
using std::bitset;
const int N(3e5+5),inf(1e9);
int n,maxa(-inf),cnt,scnt,yy;
int a[N],s[N],v[N<<1],first[N],next[N<<1];
vector<int> big;
bitset<N> book;
inline int read()
{
	int sum(0),f(1);
	char x;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			f=-1;
	for(;x>='0'&&x<='9';x=getchar())
		sum=(sum<<3)+(sum<<1)+x-'0';
	return sum*f;
}
signed main()
{
	int i,u;
	n=read();
	for(i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]>maxa)
			maxa=a[i];
	}
	for(i=1;i<=n;i++)
		if(a[i]==maxa)
			big.push_back(i),book[i]=1,cnt++;
		else if(a[i]==maxa-1)
			scnt++;
	for(i=1;i<=n;i++)
		if(book[i])
			s[i]++;
	for(i=1;i<n;i++)
	{
		u=read();v[i]=read();
		next[i]=first[u];
		first[u]=i;
		if(book[v[i]])
			s[u]++;
		v[i+n-1]=u;u=v[i];
		next[i+n-1]=first[u];
		first[u]=i+n-1;
		if(book[v[i+n-1]])
			s[u]++;
	}
	if(cnt==1)
	{
		for(int go=first[*big.begin()];go;go=next[go])
			if(a[v[go]]==maxa-1)
				yy++;
		if(yy==scnt)
			printf("%d\n",maxa);
		else
			printf("%d\n",maxa+1);
		return 0;
	}
	for(i=1;i<=n;i++)
		if(s[i]==cnt)
			break;
	if(i<=n)
		printf("%d\n",maxa+1);
	else
		printf("%d\n",maxa+2);
	return 0;
}