#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m,a;
	cin>>n>>m>>a;
	int ans=0,max=0;
	if(n%a!=0) ans++;
	if(m%a!=0) max++;
	cout<<(n/a+ans)*(m/a+max)<<endl;
	return 0;
}