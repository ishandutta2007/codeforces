#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
	int t;
    cin>>t;
	while(t--)
	{
        int m,d,w;
        cin>>m>>d>>w;
		cout<<(min(m,d)-1)/(w/__gcd(d-1,w))*min(m,d)-((1+(min(m,d)-1)/(w/__gcd(d-1,w)))*((min(m,d)-1)/(w/__gcd(d-1,w)))/2*(w/__gcd(d-1,w)))<<endl;
	} 
}