#include<iostream>
#define ll long long
using namespace std;
ll s[100010];
int main()
{
	ll a,b,i,ans,t,t1;cin>>a>>b;
	for (i=1;;i++) {s[i]=s[i-1]+i;ans=i;if (s[i]>a+b) break;}
	ans--;t=a;
	for (i=1;;i++) {t-=i;t1=i;if (t<0) break;}
	cout<<t1-1<<endl;
	for (i=1;i<=t1;i++) if (i!=s[t1]-a) cout<<i<<' ';cout<<endl;
	cout<<ans-t1+1<<endl;if (ans-t1+1!=0) cout<<s[t1]-a<<' ';
	for (i=t1+1;i<=ans;i++) cout<<i<<' ';
}