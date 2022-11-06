#include<bits/stdc++.h>
#define N 200009
using namespace std;

int n,m,ans,a[N],q[N],c[N];
void ins(int x){ for (; x<=n; x+=x&-x) c[x]++; }
int getsum(int x){
	int y=0; for (; x; x^=x&-x) y+=c[x]; return y;
}
bool cmp(int x,int y){ return a[x]-x<a[y]-y || a[x]-x==a[y]-y && x<y; }
int main(){
	scanf("%d%d",&n,&m);
	int i;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	for (i=1; i<=n; i++) q[i]=i;
	sort(q+1,q+n+1,cmp);
	int ans=0;
	for (int l=1; l<=n; l++){
		i=q[l];
		ins(i);
		int j=i+min(m-i,m-a[i])-1;
		//cout<<i<<' '<<j<<endl;
		if (j>=1) ans=max(ans,getsum(min(j,n)));
	}
	printf("%d\n",ans);
	return 0;
}