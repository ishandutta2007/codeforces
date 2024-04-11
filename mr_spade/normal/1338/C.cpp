#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100;
//inline int lg(int x)
//{
//	int t;
//	for(t=0;x>1<<t;t++);
//	return t;
//}
int sum[N];
inline void init()
{
	register int i;
	sum[0]=1;
	for(i=1;i<=50;i++)
		sum[i]=sum[i-1]+(1ll<<(2*i));
	return;
}
inline void solve()
{
	int n,m,p,n1,x,ans=0;
	register int i;
	cin>>n;m=(n+2)/3;
	if(n<=3)
		return cout<<n<<endl,void();
	for(i=0;i<=50;i++)
		if(sum[i]>=m)
		{
			p=i;break;
		}
	m=m-sum[p-1]-1;
	n1=(1ll<<(2*p))+m;
	if(n%3==1)
	{
		cout<<n1<<endl;
		return;
	}
	for(i=p;i>=0;i--)
	{
		x=m>>(i*2)&3;
		switch(x)
		{
			case 0:break;
			case 1:ans+=2*(1ll<<(i*2));break;
			case 2:ans+=3*(1ll<<(i*2));break;
			default:ans+=1ll<<(i*2);break;
		}
	}
	if(n%3==2)
		cout<<(1ll<<(2*p+1))+ans<<endl;
	else
		cout<<(n1^((1ll<<(2*p+1))+ans))<<endl;
	return;
}
signed main()
{
	int T;
	init();
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}