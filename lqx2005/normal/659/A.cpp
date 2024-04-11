#include <bits/stdc++.h>
using namespace std;
int n,a,b;
int main() 
{
	cin>>n>>a>>b;
	a+=b;
	a%=n;
	if(a<0) a+=n;
	if(a==0) a+=n;
	cout<<a<<endl;
	return 0;
}