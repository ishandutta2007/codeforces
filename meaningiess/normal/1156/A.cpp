#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int n,i,t,lst=0,ans=0;cin>>n;cin>>lst;a[1]=lst;
	for (i=2;i<=n;i++)
	{
		cin>>a[i];t=a[i];
		if (lst==1) ans+=t+1;
		if (lst==2) {if (t==3) {puts("Infinite");exit(0);}ans+=3;}
		if (lst==3) {if (t==2) {puts("Infinite");exit(0);}ans+=4;}
		lst=t;
	}
	for (i=1;i<n;i++) if (a[i]==3 && a[i+1]==1 && a[i+2]==2) ans--;
	puts("Finite");cout<<ans;
}