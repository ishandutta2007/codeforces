#include<bits/stdc++.h>
using namespace std;
struct node{
    int x,y,z;
}a[5001];
#define calc(q,w) (double)(sqrt((a[q].x-a[w].x)*(a[q].x-a[w].x)+(a[q].y-a[w].y)*(a[q].y-a[w].y)+(a[q].z-a[w].z)*(a[q].z-a[w].z)))
int main(){
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)cin>>a[x].x>>a[x].y>>a[x].z;
	double ans=1e18;
	for(int x=2;x<=n;x++)
	for(int y=2;y<x;y++)
	ans=min(ans,calc(1,x)+calc(1,y)+calc(x,y))/*,cout<<x<<','<<y<<','<<calc(1,x)<<','<<calc(1,y)<<','<<calc(x,y)<<endl*/;
	printf("%.10lf\n",ans/2);
}