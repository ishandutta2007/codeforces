#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
struct p{
	int l,r,id;
	bool operator<(const p &x)const{
		return x.r>r;
	}
}a[N],b[N];
int T,n,i,k,g[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d%d",&a[i].l,&a[i].r),a[i].id=i;
		sort(a+1,a+n+1);
		b[1]=a[1];
		k=1;
		for(i=2;i<=n;i++){
			b[++k]=a[i];
			while(k>1&&b[k-1].r>=b[k].l){
				b[k-1].r=b[k].r;
				if(b[k].l<b[k-1].l)
					b[k-1].l=b[k].l;
				k--;
			}
		}
		if(k==1){
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++)
			g[a[i].id]=1+(a[i].l>=b[1].l&&a[i].r<=b[1].r);
		for(i=1;i<=n;i++)
			printf("%d%c",g[i],i<n?' ':'\n');
	}
}