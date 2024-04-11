#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool check(int x)
{
	if(x<=1) return false;
	if(x==2) return true;
	int m=sqrt(x)+1;
	for(int i=2;i<=m;i++) if(x%i==0) return false;
	return true;
}
signed main() 
{
	cin>>n;
	if(n==1) cout<<"1"<<endl;
	else if(check(n)) cout<<"1"<<endl;
	else if(n%2==0||check(n-2)) cout<<"2"<<endl;
	else cout<<"3"<<endl;
	return 0;
}