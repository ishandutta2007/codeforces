#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=14;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,n;
char s[N];
int main()
{
	read(t);
	while(t--)
	{
		int ans,now=0;
		n=0;gets(s);
		while(s[n])++n;
		ans=n;
		F(i,0,n)
		{
			int best;
			if((i%2==1&&s[i]=='0')||(i%2==0&&s[i]=='1'));else ++now;
			if(i%2==0)--now;
			best=now+((n+1)/2-(i+1)/2);
			if(best*(best-(n-i-1))>0)if(i+1<ans)ans=i+1;
		}
		now=0;
		F(i,0,n)
		{
			int best;
			if((i%2==1&&s[i]=='1')||(i%2==0&&s[i]=='0'))++now;
			if(i%2==0)--now;
			best=now+((n+1)/2-(i+1)/2);
			if(best*(best-(n-i-1))>0)if(i+1<ans)ans=i+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}