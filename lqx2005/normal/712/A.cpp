#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n;
int a[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cout<<a[i]+a[i+1]<<" ";
	return 0;
}
//4920 4210