#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,vis[N];
struct point{
	int x,y;
	point(int a=0,int b=0):x(a),y(b){}
	point operator-(const point&rhs)const{
		return point(x-rhs.x,y-rhs.y);
	}
}a[N];
int cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
int colline(point a,point b,point c){
	return!cross(a-b,b-c);
}
int check(int p1,int p2){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
		if(colline(a[p1],a[p2],a[i]))
			vis[i]=1;
	p1=p2=-1;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&~p1)p2=i;
		else if(!vis[i])p1=i;
	for(int i=1;i<=n;i++)
		if(!vis[i]&&!colline(a[p1],a[p2],a[i]))	
			return 0;
	return 1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].x>>a[i].y;
	cout<<(check(1,2)||check(1,3)||check(2,3)?"YES\n":"NO\n");
}