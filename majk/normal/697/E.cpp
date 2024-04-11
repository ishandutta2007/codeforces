#include<bits/stdc++.h>
#define nl '\n'
#define pb push_back
#define M 1000000007
#define MAX 100000
typedef long long ll;
using namespace std;
ll poww(ll x,ll y)
{
	if(y==0) return 1;
	ll z = poww(x,y/2);
	if(y&1) return ((x%M) * ((z*z)%M))%M;
	else return (z*z)%M;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	ll i,j,k,arr[MAX+5];bool even = false;
	cin>>k;
	for(i=0;i<k;i++){
		cin>>arr[i];
		if((arr[i]&1) == 0)
			even=true;
	}
	ll pow2n=2;
	for(i=0;i<k;i++)
		pow2n = poww(pow2n,arr[i]);
	pow2n = (pow2n * poww(2,M-2))%M;
	if(even)
	{
		ll p = (pow2n + 1)%M;
		p = (p * poww(3,M-2))%M;
		cout<<p<<'/'<<pow2n<<nl;
	}
	else{
		ll p = pow2n - 1;
		if(p<0) p+=M;
		p = (p * poww(3,M-2))%M;
		cout<<p<<'/'<<pow2n<<nl;
	}
	return 0;
}