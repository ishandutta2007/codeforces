#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001];
main(){
	int n,p,l=0,r=10000000000;
    cin>>n>>p;
	for(int x=1;x<=n;x++)
    cin>>a[x];
	sort(a+1,a+n+1);
	for(int x=1;x<=n;x++)l=max(l,a[x]-x+1);
	for(int x=p;x<=n;x++)r=min(r,a[x]-x+p);
	cout<<max(r-l,0ll)<<endl;
	for(int x=l;x<r;x++)cout<<x<<' ';
}