#include <bits/stdc++.h>
using namespace std;
int a[55];
int main() {
	int t; cin>>t;
	while(t--)
	{
		int sum = 0, flag = 1;
		int n; cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		if(sum==0) cout<<"NO"<<endl;
		else{
			sort(a+1,a+n+1);
			if(sum>0)
			{
				reverse(a+1,a+n+1);
			}
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				cout<<a[i]<<" ";
			}cout<<endl;
		}
				
	}
	return 0;
}