#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
bool f1, f2;
int main() {
	int t; scanf("%d",&t);
	while(t--){
		ll a,b,c,d;
		ll x, y, x1, y1, x2 ,y2 ;
		cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
		if(a==b&&a) f1=(x+1>=x1&&x+1<=x2)||(x-1>=x1&&x-1<=x2);
		else f1 = (b-a+x>=x1&&b-a+x<=x2);
		if(c==d&&c) f2 = (y+1>=y1&&y +1<=y2)||(y-1>=y1&&y-1<=y2);
		else f2 = (d-c+y>=y1&&d-c+y<=y2);
		if(f1&&f2) puts("YES");
		else puts("NO");
	}
	return 0;
}