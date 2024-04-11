#include<iostream>
#define ll long long
using namespace std;
ll gcd(ll x,ll y) {return !y?x:gcd(y,x%y);}
int main()
{
	ll a,b,c,d,t1,t2;cin>>a>>b>>c>>d;t1=gcd(c,d),c/=t1,d/=t1;cout<<min(a/c,b/d);
}