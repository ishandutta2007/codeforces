#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long l,k;
	int ans=0;
	cin>>k>>l;
	while(l%k==0)
	{
		ans++;
		l/=k;
	}
	if(l==1) cout<<"YES"<<endl<<ans-1<<endl;
	else     cout<<"NO"<<endl;
	return 0;
}