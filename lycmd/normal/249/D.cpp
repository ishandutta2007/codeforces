#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,m,a,b,c,d,tot,x[N],y[N],s[N];
char o;
struct point{
	int x,y;
	int operator<(const point&rhs)const{
		return x<rhs.x||(x==rhs.x&&y>rhs.y);
	}
};
point p[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>a>>o>>b>>c>>o>>d;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		if(c*x>d*y&&b*y>a*x)
			p[++m]={c*x-d*y,b*y-a*x};
	}
	sort(p+1,p+1+m);
	for(int i=1;i<=m;i++)
		if(p[i].y>s[tot])
			s[++tot]=p[i].y;
		else
			*lower_bound(s+1,s+1+tot,p[i].y)=p[i].y;
	cout<<tot<<"\n";
	return 0;
}