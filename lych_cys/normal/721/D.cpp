#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;

int n,m,x;
struct node{
	ll x; int y,z;
}a[N];
bool operator <(node u,node v){ return u.x>v.x; }
bool cmp(node u,node v){ return u.y<v.y; }
priority_queue<node> q;
int read(){
	int x=0; char cr=getchar(); bool flag=0;
	while (cr<'0' || cr>'9'){ if (cr=='-') flag=1; cr=getchar(); }
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return (flag)?-x:x;
}
void opt(){
	int i;
	for (i=1; i<=n; i++){
		if ((a[i].z<0) && (a[i].x!=0)) putchar('-');
		printf("%lld ",a[i].x);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&x);
	int i,j,k; bool flag=0,flag2=0;
	for (i=1; i<=n; i++){
		a[i].x=read(); if (a[i].x<0) flag=!flag;
			if (!a[i].x) flag2=1; a[i].y=i; a[i].z=((a[i].x)<0)?-1:1;
	}
	if (flag2){
		for (i=1; i<=n; i++) if (!a[i].x){
			if (!flag) a[i].z=-1; break;
		}
		flag=1;
	}
	for (i=1; i<=n; i++) a[i].x=abs(a[i].x);
	if (!flag){
		for (i=2,k=1; i<=n; i++)
			if (a[i].x<a[k].x) k=i;
		if (a[k].x>=(ll)m*x){
			a[k].x-=(ll)m*x;
			opt();return 0;
		} else{
			//puts("233");
			j=(a[k].x/x+1); m-=j;
			a[k].x-=(ll)j*x;
			a[k].z=-a[k].z; a[k].x=-a[k].x;
			//cout<<k<<' '<<a[k].z<<endl;
		}
	}
	for (i=1; i<=n; i++) q.push(a[i]);
	while (m--){
		node u=q.top(); q.pop();
		u.x+=x; q.push(u);
	}
	n=0;
	while (!q.empty()){ a[++n]=q.top(); q.pop(); }
	sort(a+1,a+n+1,cmp);
	opt();
	return 0;
}