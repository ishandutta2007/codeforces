#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1200002;
int T,n,m,k,i,a[N],L[N],R[N],f[N],cnt,ans;
int D,t[N];
struct p{
	int val,l,r;
	bool operator<(const p &k)const{
		return k.val>val;
	}
}x[N];
void init(){
	scanf("%d",&n);
	m=0;k=0;ans=0;
	for(i=1;i<=n;i++)
		L[i]=R[i]=f[i]=0;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(!L[a[i]]){
			L[a[i]]=i;
			m++;
		}
		R[a[i]]=i;
	}
	for(i=1;i<=n;i++)
		if(L[a[i]]==i)
			x[++k]=(p){a[i],L[a[i]],R[a[i]]};
	sort(x+1,x+m+1);	
}
int max(int x,int y){
	return x>y?x:y;
}
void work(){
	ans=f[1]=1;
	for(i=2;i<=m;i++){
		if(x[i-1].r<x[i].l)
			f[i]=f[i-1]+1;
		else
			f[i]=1;
		ans=max(ans,f[i]);
	}
	printf("%d\n",m-ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
}