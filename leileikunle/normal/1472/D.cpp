#include <bits/stdc++.h>
using namespace std;
#define int long long 
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int a[200005] = {0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		int sum1 = 0, sum2 = 0;
		for(int i=1;i<=n;i++)
		{
			if(i%2){
				if(a[i]%2==0) sum1 += a[i];
			}else{
				if(a[i]%2!=0) sum2 += a[i];
			}
		}
		if(sum1>sum2) cout<<"Alice"<<endl;
		else if(sum1==sum2) cout<<"Tie"<<endl;
		else cout<<"Bob"<<endl;
	}
}