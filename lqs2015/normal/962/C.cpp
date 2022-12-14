#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[111],p,cnt,cur,ans,aa;
double k;
int main()
{
	cin>>n;
	ans=1e9;
	while(n)
	{
		a[cnt++]=n%10;
		n/=10;
	}
	for (int i=1;i<(1<<cnt);i++)
	{
		cur=p=0;
		for (int j=0;j<cnt;j++)
		{
			if (i&(1<<j)) 
			{
				p+=pow(10,cur)*a[j];
				cur++;
				aa=a[j];
			}
		}
		if (!aa) continue;
		k=sqrt(p);
		if (k==(int)k) ans=min(ans,cnt-cur);
	}
	if (ans==1e9) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}