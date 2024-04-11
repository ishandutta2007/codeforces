#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,q,sa[N],sb[N],ta[N],tb[N];
char s[N],t[N];
int main()
{
	gets(s);gets(t);
	while(s[n])++n;
	while(t[m])++m;
	F(i,0,n)if(s[i]=='C')s[i]='B';
	F(i,0,m)if(t[i]=='C')t[i]='B';
	F(i,0,n)
	{
		sb[i+1]=sb[i];
		if(s[i]=='A')++sa[i+1],sa[i+1]=sa[i]+1;else ++sb[i+1];
	}
	F(i,0,m)
	{
		tb[i+1]=tb[i];
		if(t[i]=='A')++ta[i+1],ta[i+1]=ta[i]+1;else ++tb[i+1];
	}
	read(q);
	while(q--)
	{
		int sl,sr,tl,tr;
		read(sl);read(sr);read(tl);read(tr);
		--sl,--tl;
		if(sb[sr]-sb[sl]>tb[tr]-tb[tl]||(sb[sr]-sb[sl]-tb[tr]+tb[tl])&1)
			putchar('0');
		else
		{
			if(sb[sr]==sb[sl]&&tb[tr]==tb[tl])
			{
				if(sr-sl>=tr-tl&&(sr-sl-tr+tl)%3==0)putchar('1');
				else putchar('0');
			}
			else
			{
				if(sb[sr]==sb[sl])
				{
					if(sr-sl<=ta[tr])putchar('0');
					else putchar('1');
				}
				else
				{
					if(tb[tr]-tb[tl]-sb[sr]+sb[sl]==0)
					{
						putchar(sa[sr]>=ta[tr]&&(sa[sr]-ta[tr])%3==0?'1':'0');
					}
					else
					{
						putchar(sa[sr]>=ta[tr]?'1':'0');
					}
				}
			}
		}
	}
	return 0;
}