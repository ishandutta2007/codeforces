#include<bits/stdc++.h>
#define point pair<int,int>
#define x first
#define y second
#define p(a,b) (a[b.x][b.y])
using namespace std;
int const N=1010;
int n,m,q,a[N][N];
point l[N][N],r[N][N],u[N][N],d[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			u[i][j]={i-1,j},l[i][j]={i,j-1},
			d[i][j]={i+1,j},r[i][j]={i,j+1};
	while(q--){
		int ax,ay,bx,by,h,w;
		cin>>ax>>ay>>bx>>by>>h>>w;
		point p1=r[1][0],p2=r[1][0];
		for(int i=1;i<ax;i++)p1=p(d,p1);
		for(int i=1;i<bx;i++)p2=p(d,p2);
		for(int i=1;i<ay;i++)p1=p(r,p1);
		for(int i=1;i<by;i++)p2=p(r,p2);
		for(int i=0;i<w;i++,p1=p(r,p1),p2=p(r,p2)){
			point a1=p1,a2=p(u,a1),
				  b1=p2,b2=p(u,b1);
			p(u,a1)=b2,p(u,b1)=a2,
			p(d,a2)=b1,p(d,b2)=a1;
		}
		p1=p(l,p1),p2=p(l,p2);
		for(int i=0;i<h;i++,p1=p(d,p1),p2=p(d,p2)){
			point a2=p1,a1=p(r,a2),
				  b2=p2,b1=p(r,b2);
			p(l,a1)=b2,p(l,b1)=a2,
			p(r,a2)=b1,p(r,b2)=a1;
		}
		p1=p(u,p1),p2=p(u,p2);
		for(int i=0;i<w;i++,p1=p(l,p1),p2=p(l,p2)){
			point a2=p1,a1=p(d,a2),
				  b2=p2,b1=p(d,b2);
			p(u,a1)=b2,p(u,b1)=a2,
			p(d,a2)=b1,p(d,b2)=a1;
		}
		p1=p(r,p1),p2=p(r,p2);
		for(int i=0;i<h;i++,p1=p(u,p1),p2=p(u,p2)){
			point a1=p1,a2=p(l,a1),
				  b1=p2,b2=p(l,b1);
			p(l,a1)=b2,p(l,b1)=a2,
			p(r,a2)=b1,p(r,b2)=a1;
		}
	}
	for(point i=r[1][0];i.x<=n;i=d[i.x][i.y],cout<<"\n")
		for(point p=i;p.y<=m;p=r[p.x][p.y])
			cout<<a[p.x][p.y]<<" ";
}