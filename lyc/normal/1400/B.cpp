#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,vv1,vv2,n1,n2,www1,www2,T,ans,j,k,l;
signed main()
{
	cin>>T;
	while(T--)
	{   
	    ans=0;
		cin>>vv1>>vv2>>n1>>n2>>www1>>www2;
		if(www1>www2)
		{
			swap(www1,www2);
			swap(n1,n2);
		}
		for(int i=0;i<=n1;i++)
		{
			if(i*www1<=vv1){
				j=min(n2,(vv1-(i*www1) )/www2);
				k=min(n1-i,vv2/www1);
				l=min(n2-j,(vv2-(www1*k))/www2);
				if(i+j+k+l>ans)
				ans=i+j+k+l;
			}
			else break;
		}
		cout<<ans<<endl;
	}
}