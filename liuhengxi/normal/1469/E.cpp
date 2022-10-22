#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define ret goto end;
using namespace std;
const int N=(1<<20)+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
inline void putbin(int x,int k){for(int i=k-1;~i;--i){putchar((x>>i&1)|48);}putchar('\n');}
int q,n,k,c[N];
char s[N];
int main()
{
	read(q);
	while(q--)
	{
		int log=0;
		read(n);read(k);
		while((1<<log)<n)++log;
		scanf("%s",s);
		if(n==1){puts("YES");puts(s);ret;}
		if(k<=log)
		{
			F(i,0,1<<k)c[i]=0;
			F(i,0,n-k+1)
			{
				int mask=0;
				F(j,0,k)mask=mask<<1|(s[i+j]!='1');
				c[mask]=1;
			}
			F(i,0,1<<k)if(!c[i]){puts("YES");putbin(i,k);ret;}
			puts("NO");ret;
		}
		else
		{
			int last0=-1;
			F(i,0,1<<log)c[i]=0;
			F(i,0,k-log-1)if(s[i]=='0')last0=i;
			F(i,0,n-k+1)
			{
				if(s[i+k-log-1]=='0')last0=i+k-log-1;
				if(last0>=i)continue;
				int mask=0;
				F(j,0,log)mask=mask<<1|(s[i+k-log+j]!='1');
				c[mask]=1;
			}
			F(i,0,1<<log)if(!c[i]){puts("YES");F(i,0,k-log)putchar('0');putbin(i,log);ret;}
		}
		end:;
	}
	return 0;
}