#include<bits/stdc++.h>
using namespace std;
#define re register
inline int cmax(re int a,re int b){return a>b?a:b;}
inline int sol(re int n,re int p)
{
	return (n-1)/(p-1)*p+(n-1)%(p-1)+1;
}
int main()
{
	re int n1,n2,p1,p2;
	cin>>n1>>n2>>p1>>p2;
	cout<<cmax(cmax(sol(n1,p1),sol(n2,p2)),sol(n1+n2,p1*p2));
}