#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define N 1000009
using namespace std;

int n,A,B;
struct node{ int x,y; }a[N];
bool cmp(node u,node v){ return u.x<v.x; }
void solve(int A,int B,int now,bool flag){
	int i,tmp=(A-1)/a[now].x+now;
	if (tmp>n) return;
	if ((ll)(n-tmp)*a[tmp+1].x>=B){
		puts("Yes");
		if (!flag){
			printf("%d %d\n",tmp-now+1,n-tmp);
			for (i=now; i<=tmp; i++) printf("%d ",a[i].y); puts("");
			for (i=tmp+1; i<=n; i++) printf("%d ",a[i].y); puts("");
		} else{
			printf("%d %d\n",n-tmp,tmp-now+1);
			for (i=tmp+1; i<=n; i++) printf("%d ",a[i].y); puts("");
			for (i=now; i<=tmp; i++) printf("%d ",a[i].y); puts("");
		}
		exit(0);
	}
}
int main(){
	scanf("%d%d%d",&n,&A,&B);
	int i;
	for (i=1; i<=n; i++){
		scanf("%d",&a[i].x); a[i].y=i;
	}
	sort(a+1,a+n+1,cmp);
	for (i=1; i<=n; i++){
		solve(A,B,i,0); solve(B,A,i,1);
	}
	puts("No");
	return 0;
}