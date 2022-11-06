#include<bits/stdc++.h>
#define N 200009
using namespace std;

int n,m; struct node{ int x,y,id; }a[N];
bool cmp(node u,node v){ return u.y<v.y; }
bool check(int lim){
	int i,rst=m,tmp=0;
	for (i=1; i<=n; i++) if (a[i].x>=lim && a[i].y<=rst){
		tmp++; rst-=a[i].y;
	}
	return tmp>=lim;
}
void opt(int lim){
	printf("%d\n%d\n",lim,lim);	
	int i,tmp=0;
	if (!lim) return;
	for (i=1; i<=n; i++) if (a[i].x>=lim){
		tmp++; printf("%d ",a[i].id);
		if (tmp==lim) break;
	}
	puts("");
}
int main(){
	scanf("%d%d",&n,&m);
	int i;
	for (i=1; i<=n; i++){
		scanf("%d%d",&a[i].x,&a[i].y); a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	int l=0,r=n,mid;
	while (l<r){
		mid=l+r+1>>1;
		if (check(mid)) l=mid; else r=mid-1;	
	}
	opt(l);
	return 0;
}