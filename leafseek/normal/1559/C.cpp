#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100000+5;
int arr[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n;
	while(T--)
	{
		cin>>n;
		rep(i,1,n) cin>>arr[i];
		if(arr[1]==1)
		{
			cout<<(n+1)<<' ';
			rep(i,1,n)
				cout<<i<<' ';
			cout<<endl;
		}
		else if(arr[n]==0)
		{
			rep(i,1,n+1)
				cout<<i<<' ';
			cout<<endl;
		}
		else
		{
			register bool flag=false;
			rep(i,1,n-1)
				if(arr[i]==0&&arr[i+1]==1)
				{
					rep(j,1,i)
						cout<<j<<' ';
					cout<<(n+1)<<' ';
					rep(j,i+1,n)
						cout<<j<<' ';
					cout<<endl;
					flag=true;break;
				}
			assert(flag);
		}
	}
	return 0;
}