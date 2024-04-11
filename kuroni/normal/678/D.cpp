#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;
main()
{
    long long A,B,n,x;
	cin>>A>>B>>n>>x;
	do
    {
		if (n % 2 != 0) x=(A*x + B) % mod;
		B = B*(A+1) % mod;
		A=A*A % mod;
		n/=2;
	} while (n >= 1);
	cout<<x;
}