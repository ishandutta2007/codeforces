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
int n,a[N];
char s[10];
int mn()
{
	int a=0;
	for(int i=0;s[i];++i)
	{
		if(s[i]=='?')if(i==0)a=1;else a*=10;
		else a=a*10+s[i]-'0';
	}
	return a;
}
int mx()
{
	int a=0;
	for(int i=0;s[i];++i)
	{
		if(s[i]=='?')a=a*10+9;
		else a=a*10+s[i]-'0';
	}
	return a;
}
int main()
{
	read(n);
	gets(s);
	a[0]=mn();
	F(i,1,n)
	{
		bool bad=false;
		gets(s);
		for(int k=0;s[k]&&!bad;++k)if(s[k]=='?')
		{
			F(j,k?0:1,11)
			{
				if(j==10){bad=true;break;}
				s[k]=j+'0';
				if(mx()>a[i-1])break;
			}
		}
		if(bad)return puts("NO"),0;
		a[i]=mx();
		if(a[i]<=a[i-1])return puts("NO"),0;
	}
	puts("YES");
	F(i,0,n)printf("%d\n",a[i]);
	return 0;
}