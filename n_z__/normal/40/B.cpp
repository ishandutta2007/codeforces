#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,x;
	cin>>n>>m>>x;
	n-=2*x-1,m-=2*x-1;
	if(min(n,m)<0)cout<<0;
	else cout<<max(n+m,1);
}