#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7;int n,r1,r2;
int main()
{
	scanf("%d",&n),r1=1,r2=1;
	for(int i=1;i<=n;i++) r1=1ll*r1*i%P;
	for(int i=1;i<n;i++) r2=2ll*r2%P;
	return printf("%d\n",(r1-r2+P)%P),0;
}