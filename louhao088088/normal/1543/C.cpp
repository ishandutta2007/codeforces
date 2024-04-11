#include<bits/stdc++.h>
using namespace std;
#define double long double
const int maxn=4e5+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int T;
double a,b,c,d,ans;
void dfs(double a,double b,double c,int num,int sum,double p,int f)
{
	//cout<<f<<" "<<a<<" "<<b<<" "<<c<<" "<<sum<<" "<<num<<endl;
	if(f==3){double g=p*num;for(int i=1;i<=num;i++)g=g/1000;ans=ans+g;return;}
	if(a>d)dfs(a-d,b<=1e-6?0:b+d/(sum-1),c<=1e-6?0:c+d/(sum-1),num+1,sum,p*a,1);
	if(a>0&&a<=d)dfs(0,b<=1e-6?0:b+a/(sum-1),c<=1e-6?0:c+a/(sum-1),num+1,sum-1,p*a,1);
	if(b>d)dfs(a<=1e-6?0:a+d/(sum-1),b-d,c<=1e-6?0:c+d/(sum-1),num+1,sum,p*b,2);
	if(b>0&&b<=d)dfs(a<=1e-6?0:a+b/(sum-1),0,c<=1e-6?0:c+b/(sum-1),num+1,sum-1,p*b,2);
	if(c>d)dfs(a<=1e-6?0:a+d/(sum-1),b<=1e-6?0:b+d/(sum-1),c-d,num+1,sum,p*c,3);
	if(c>0&&c<=d)dfs(a<=1e-6?0:a+c/(sum-1),b<=1e-6?0:b+c/(sum-1),0,num+1,sum-1,p*c,3);
}
signed main()
{
	T=read();
	while(T--)
	{
		cin>>a>>b>>c>>d;ans=0;
		a=a*1000,b=b*1000,c=c*1000,d=d*1000;
		dfs(a,b,c,0,3,1,0);
		cout<<setprecision(13)<<ans<<endl;
	}
	return 0;
}