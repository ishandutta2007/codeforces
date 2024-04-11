#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=4e6+5,MOD=51123987;
int n,len[N],l[N],r[N];
char s[N],t[N];
void manacher()
{
	int md=0,ri=0;
	F(i,0,2*n)
	{
		if(i<ri)len[i]=min(ri-i-1,len[2*md-i]);
		while(len[i]<i&&s[i-len[i]-1]==s[i+len[i]+1])++len[i];
		if(i+len[i]>ri)ri=i+len[i]+1,md=i;
	}
}
int main()
{
	long long pa=0,pre=0,ans=0;
	read(n);
	scanf("%s",t);
	F(i,0,n)s[i<<1]=t[i],s[i<<1|1]='#';
	manacher();
	F(i,0,2*n-1)
	{
		pa+=(len[i]+2-(i&1))>>1;
		++l[i-len[i]];--l[i+1];
		++r[i+1];--r[i+len[i]+2];
	}
	F(i,0,2*n-1)l[i+1]+=l[i],r[i+1]+=r[i];
	F(i,0,n)
	{
		pre+=r[2*i+1];(pre>=MOD)&&(pre-=MOD);
		(ans+=pre*l[2*i+2])%=MOD;
	}
	pa%=MOD;
	ans=(pa*(pa-1)>>1)%MOD-ans;
	ans+=ans>>63&MOD;
	printf("%lld\n",ans);
	return 0;
}