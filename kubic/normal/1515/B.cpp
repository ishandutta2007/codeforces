#include <bits/stdc++.h>
using namespace std;
int T,n,t;
void slv()
{
	scanf("%d",&n);if(n&1) {puts("NO");return;}t=sqrt(n);
	if(t*t==n) {puts("YES");return;}n/=2;t=sqrt(n);
	if(t*t==n) {puts("YES");return;}puts("NO");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0; 
}