#include<bits/stdc++.h>
#define ll long long
#define N 200009
using namespace std;

int m,n,tp,cnt;
struct point{ int x,y; };
struct node{ point p; int id; }a[N],b[N],q[N];
point operator -(point u,point v){ return (point){u.x-v.x,u.y-v.y}; }
ll crs(point u,point v){ return (ll)u.x*v.y-(ll)u.y*v.x; }
ll dot(point u){ return (ll)u.x*u.x+(ll)u.y*u.y; }
bool cmp(node u,node v){
	ll tmp=crs(u.p-b[1].p,v.p-b[1].p);
	if (tmp>0 || !tmp && dot(u.p-b[1].p)<dot(v.p-b[1].p)) return 1;
	return 0;
}
int main(){
	scanf("%d%d%*d%*d",&m,&n);
	int i,x,y; point u,v,p;
	u.x=v.y=0;
	for (i=1; i<=m; i++){
		scanf("%d%d",&x,&y); p=(point){x,y};
		a[i]=(node){p,i};
		if (p.x>u.x || p.x==u.x && p.y<u.y) u=p;
		if (p.y>v.y || p.y==v.y && p.x<v.x) v=p;
	}
	for (i=1; i<=n; i++){
		scanf("%d%d",&x,&y); p=(point){x,y};
		a[i+m]=(node){p,-i};
		if (p.x>u.x || p.x==u.x && p.y<u.y) u=p;
		if (p.y>v.y || p.y==v.y && p.x<v.x) v=p;
	}
	b[1]=(node){(point){u.x,0},0};
	b[cnt=2]=(node){(point){0,v.y},0};
	for (i=1; i<=m+n; i++) if (a[i].p.x>=v.x && a[i].p.y>=u.y) b[++cnt]=a[i];
	sort(b+2,b+cnt+1,cmp);
	q[1]=b[1]; q[tp=2]=b[2];
	for (i=3; i<=cnt; i++){
		if (b[i].p.x==q[tp].p.x && b[i].p.y==q[tp].p.y){
			if (b[i].id>q[tp].id) q[tp]=b[i]; continue;
		}
		for (; tp>1 && crs(b[i].p-q[tp-1].p,q[tp].p-q[tp-1].p)>0; tp--);
		q[++tp]=b[i];
		if (!b[i].p.x) break;
	}
	for (i=1; i<=tp; i++) if (q[i].id>0){
		puts("Max"); return 0;
	}
	puts("Min");
	return 0;
}