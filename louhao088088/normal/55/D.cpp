#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	char ch=getchar();int x=0;bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int mod=2520;
int f[25][2525][50];
int p[50],n,m,t,id[2525],s[30],tot,sum;
inline int lcm(int a,int b){if(a==0)a=1;if(b==0)b=1;return a*b/__gcd(a,b);}
int dfs(int pos,int num,int lm,int flag)
{
	//cout<<pos<<" "<<num<<" "<<lm<<" "<<flag<<" "<<(num%lm)<<endl;
	if(pos==0){if(num%lm==0)return 1;return 0;}
	int res=0;
	if(flag==0&&f[pos][num][id[lm]]!=-1)return f[pos][num][id[lm]];
	if(flag==0)
	{
		for(int i=0;i<=9;i++)
		{
			res=res+dfs(pos-1,(num*10+i)%mod,lcm(i,lm),0);
		}
		f[pos][num][id[lm]]=res;
	}
	else
	{
		for(int i=0;i<s[pos];i++)
		{
			res=res+dfs(pos-1,(num*10+i)%mod,lcm(i,lm),0);
		}
		res+=dfs(pos-1,(num*10+s[pos])%mod,lcm(s[pos],lm),1);
	}return res;
}
int getans(int x)
{
	sum=0;int res=0;
	while(x>0)
	{
		s[++sum]=x%10;x=x/10;
	}res=dfs(sum,0,1,1);
	return res;
}
signed main()
{
	t=read();
	for(int i=1;i<=mod;i++)
		if(mod%i==0)p[++tot]=i,id[i]=tot;
	memset(f,-1,sizeof f);
	while(t--)
	{
		n=read(),m=read();
		printf("%lld\n",getans(m)-getans(n-1));
	}
	return 0;
}