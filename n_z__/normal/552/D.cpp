#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y;
}a[2001];
main(){
    int n,ans=0;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>a[x].x>>a[x].y;
	for(int x=1;x<=n;x++)
	for(int y=x+1;y<=n;y++)
	for(int z=y+1;z<=n;z++)
    if((a[y].y-a[x].y)*(a[z].x-a[x].x)!=(a[z].y-a[x].y)*(a[y].x-a[x].x))ans++;
	cout<<ans;
}