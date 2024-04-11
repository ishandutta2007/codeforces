#include <bits/stdc++.h>
#define int long long int
using namespace std;
bool judge(int n)
{
	int s = n;
	while(n)
	{
		int e = n % 10;
		if(e>0) if(s%e) return false;
		n /= 10;
	}
	return true;
}
signed main()
{
	
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		while(1)
		{
			if(judge(n))
			{
				break;
			}
			n++;
		}
		cout<<n<<endl;
	}
}