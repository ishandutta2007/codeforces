#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10001];
main(){
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x];
    int ans=0;
	for(int x=1;x<=n;x+=2)
	for(int y=x+1,u=0,v=0;y<=n;y+=2)
    ans+=max(0ll,min(a[x]-u+!!(u),a[y]-v+!!(v))),u+=a[y]-min(v,a[y]),v-=min(v,a[y])-a[y+1];
	cout<<ans<<endl;
}