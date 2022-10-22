#include<bits/stdc++.h>
using namespace std;
int f[30],ans[30];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int main()
{
	int q,i,t;cin>>q;f[0]=1;
	for (i=1;i<=26;i++) f[i]=f[i-1]*2;
	while (q--)
	{
		cin>>t;
		for (i=1;i<=26;i++) if (f[i]>t) break;
		if (f[i]-1!=t) {cout<<f[i]-1<<endl;continue;}
		else if (ans[i]) {cout<<ans[i]<<endl;continue;}
		else
		{
			int j=i,lim=sqrt(t);
			for (i=2;i<=lim;i++) if (t%i==0) {ans[j]=t/i;break;}
			if (!ans[j]) ans[j]=1;cout<<ans[j]<<endl;
		}
	}
}