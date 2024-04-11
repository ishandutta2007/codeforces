#include <bits/stdc++.h>
#define maxn 1500005
int p[maxn],at[maxn],n,p1[maxn],p2[maxn],tail=0;

void swap(int a,int b) {
	//if (2*(a-b)<n) {printf("!!!");return ;}
	int ta=p[a],tb=p[b];
	at[ta]=b; at[tb]=a;
	p[a]=tb; p[b]=ta;
	p1[++tail]=a;p2[tail]=b;
}

int get(int i) {
	int d=at[i];
	if (d==i) return 0;
	if (d<=n/2) {swap(d,n);d=at[i];}
	else {swap(d,1);d=at[i];}
	if (abs(d-i)<n/2) {swap(d,n-d+1);d=at[i];}
	swap(d,i); return 0;
}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		scanf("%d",&p[i]);
		at[p[i]]=i;
	} for (int i=n-1;i>=2;i--) {
		get(i);
	} if (p[1]!=1) {
		swap(1,n);
	}printf("%d\n",tail);
	for (int i=1;i<=tail;++i) printf("%d %d\n",p1[i],p2[i]);
	//for (int i=1;i<=n;++i) printf("%d ",at[i]);
	return 0;
}