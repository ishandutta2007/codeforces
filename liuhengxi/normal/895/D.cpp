#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,MOD=1000000007;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,cnt[30],cnt1[30],cnt2[30],f[N]={1},fi[N]={1},ans;
char s[N],t[N];
bool dif;
int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		(a*=a)%=MOD;b>>=1;
	}
	return (int)c;
}
int inv(int a){return pow(a,MOD-2);}
int main()
{
	gets(s);gets(t);
	while(s[n])++n;
	F(i,0,n)++cnt[s[i]-'a'];
	F(i,1,n+1)f[i]=f[i-1]*(long long)i%MOD;
	F(i,1,n+1)fi[i]=fi[i-1]*(long long)inv(i)%MOD;
	F(i,0,n)
	{
		if(dif)
		{
			bool bad=false;
			long long tmp=f[n-i-1];
			F(k,0,26)
			{
				(tmp*=fi[cnt[k]-cnt1[k]])%=MOD;
			}
			F(j,s[i]-'a'+1,26)
			{
				int x=cnt[j]-cnt1[j];
				(ans+=tmp*x%MOD)%=MOD;
			}
			tmp=f[n-i-1];
			F(k,0,26)
			{
				if(cnt2[k]>cnt[k]){bad=true;break;}
				(tmp*=fi[cnt[k]-cnt2[k]])%=MOD;
			}
			if(!bad)
				F(j,0,t[i]-'a')
				{
					int x=cnt[j]-cnt2[j];
					(ans+=tmp*x%MOD)%=MOD;
				}
		}
		else if(s[i]!=t[i])
		{
			long long tmp=f[n-i-1];
			F(k,0,26)
			{
				(tmp*=fi[cnt[k]-cnt1[k]])%=MOD;
			}
			F(j,s[i]-'a'+1,t[i]-'a')
			{
				int x=cnt[j]-cnt1[j];
				(ans+=tmp*x%MOD)%=MOD;
			}
			dif=true;
		}
		++cnt1[s[i]-'a'];
		++cnt2[t[i]-'a'];
	}
	printf("%d\n",ans);
	return 0;
}