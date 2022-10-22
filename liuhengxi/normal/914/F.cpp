#include<cstdio>
#include<bitset>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
char s[N],t[N];
int n,q;
bitset<N> c[26],m,all;
int main()
{
	all.set();
	scanf("%s",s);
	while(s[n])++n;
	F(i,0,n)c[s[i]-'a'][i]=1;
	for(read(q);q--;)
	{
		int opt;read(opt);
		if(opt==1)
		{
			int i;--read(i),scanf("%s",t);
			c[s[i]-'a'][i]=0;
			c[(s[i]=t[0])-'a'][i]=1;
		}
		if(opt==2)
		{
			int l,r,len=0;
			read(l,r);--l;
			scanf("%s",t);
			while(t[len])++len;
			r-=len-1;
			if(l<r)
			{
				m=all<<r^all<<l;
				F(i,0,len)
				{
					int x=t[i]-'a';
					m&=c[x];m<<=1;
				}
				printf("%d\n",int(m.count()));
			}
			else puts("0");
		}
	}
	return 0;
}