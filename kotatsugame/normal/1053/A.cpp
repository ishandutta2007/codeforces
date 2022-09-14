#include<iostream>
using namespace std;
long long n,m,k;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
main()
{
	cin>>n>>m>>k;
	if(2*n*m%k)cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		cout<<"0 0"<<endl;
		if(k%2==0)
		{
			k/=2;
			long long g=gcd(n,k);
			n/=g;
			k/=g;
			m/=gcd(m,k);
			cout<<n<<" 0"<<endl;
			cout<<"0 "<<m<<endl;
		}
		else
		{
			long long g=gcd(n,k);
			if(g>2)
			{
				n/=g;n*=2;
				k/=g;
				m/=gcd(m,k);
			}
			else
			{
				n/=g;
				k/=g;
				m/=gcd(m,k);m*=2;
			}
			cout<<n<<" 0"<<endl;
			cout<<"0 "<<m<<endl;
		}
	}
}