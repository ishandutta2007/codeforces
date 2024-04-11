#include <iostream>
#include <fstream>

using namespace std;

int n,p,t;


void solve2(int n,int p)
{
	for (int i=1;i<n;++i)
		cout<<i<<" "<<i+1<<"\n";
	cout<<n<<" "<<1<<"\n";
	for (int i=1;i<n-1;++i)
		cout<<i<<" "<<i+2<<"\n";
	cout<<n<<" "<<2<<"\n";
	cout<<n-1<<" "<<1<<"\n";
	
	int cnt=0;
	for (int i=1;i<n;++i)
		for (int j=i+1;j<=n;++j)
		{
			if (cnt==p)
				break;
			if (j-i==1 || j-i==2)
				continue;
			if (i==1 && j==n)
				continue;
			if (i==1 && j==n-1)
				continue;
			if (i==2 && j==n)
				continue;
			cout<<i<<" "<<j<<"\n";
			++cnt;
		}
	
}

int main()
{
	cin>>t;
	for (int i=0;i<t;++i)
	{
		cin>>n>>p;
		solve2(n,p);
	}

}