#include<bits/stdc++.h>
using namespace std;
const int N=400010;
int t,n,ans[N];
struct d{
	int h,w,nam;
	bool operator < (const d x) const{if(h!=x.h)return h<x.h;else return w>x.w;}
}a[N];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&a[i].h,&a[i].w);
			a[i].nam=i;
			ans[i]=-1;
		}
		for(int i=1;i<=n;i++){
			a[i+n].nam=i;
			a[i+n].h=a[i].w;
			a[i+n].w=a[i].h;
		}
		sort(a+1,a+2*n+1);
		int minn=2e9,where=0,ovo=0;
		for(int i=1;i<=2*n;i++){
			if(a[i].w>minn&&ovo==1){
				ans[a[i].nam]=where;
			}
			if(a[i+1].h!=a[i].h){
				ovo=1;
				if(minn>a[i].w)where=a[i].nam;
				minn=min(minn,a[i].w);
			}
		}
		for(int i=1;i<=n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}