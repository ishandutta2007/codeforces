#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
int main()
{
	ll x,y;int q;cin>>q;
    while(q--)
	{
        ll ans=0;cin>>x>>y;
        if(y%2==x%2)ans=y*(y%2==1?-1:1),y--;
        if(y<x){cout<<ans<<endl;continue;}
        ll t=(y-x+1)/2;
        ans+=(y%2==1?-1:1)*(x+1+y)*t/2;
        ans+=(x%2==1?-1:1)*(x+y-1)*t/2;
        cout<<ans<<endl;
	}
}