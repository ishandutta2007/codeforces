#include<bits/stdc++.h>
using namespace std;
int a[401];
int main(){
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>a[x];
	unsigned ans=-1;
	for(int x=1;x<=n;x++)
	for(int y=x;y<=n;y++)
	{
	    int u=1,v=a[y],now=a[x]-1;
	    for(int z=1;z<=y;z++)
	    u+=now/a[z],v+=now/a[z]*a[z],now%=a[z];
	    now=v;
	    for(int z=1;z<=n;z++)
	    u-=now/a[z],now%=a[z];
	    if(u<0)ans=min(ans,(unsigned)v);
	}
	cout<<(int)ans<<endl;
}