#include <bits/stdc++.h>
using namespace std;
int main()
{
    int tt = 1;
    cin>>tt;
    while(tt--)
    {
        int n; cin>>n;
	if(n%2==1)
	{
		for(int i=1;i<=n/2-1;i++) 
		{
			cout<<i*2<<" "<<i*2-1<<" ";
		}
		cout<<n<<" "<<n-2<<" "<<n-1<<endl;;
	}else
	{
		for(int i=1;i<=n/2;i++) cout<<i*2<<" "<<i*2-1<<" ";
		cout<<endl;
	}
    }
}