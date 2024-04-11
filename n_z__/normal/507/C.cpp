#include<bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int n,h,a=0,q=0;
	cin>>h>>n;
	n--;
	while(h--)
		if(n>>h&1^q)a+=1ll<<(h+1);
		else a++,q^=1;
	cout<<a;
}