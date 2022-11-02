#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=1000002;
int n,q,B,i,j,k,a[N],cnt[N],L,R;
struct Uzi{
	int l,r,o,id;
	bool operator<(const Uzi &k)const{
		if(k.o!=o)
			return k.o<o;
		if(k.o&1)
			return k.r<r;
		return k.r>r;
	}
}f[N];
long long sum,Ans[N];
void init(){
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	B=(int)(q/sqrt(1.5*n))+1;
	for(i=1;i<=q;i++){
		scanf("%d%d",&f[i].l,&f[i].r);
		f[i].o=f[i].l/B;
		f[i].id=i;
	}
	sort(f+1,f+q);
}
void work(){
	L=f[1].l;R=f[1].l-1;
	for(i=1;i<=q;i++){
		while(R<f[i].r){
			R++;
			sum+=1ll*a[R]*(cnt[a[R]]*2+1);
			cnt[a[R]]++;
		}
		while(L>f[i].l){
			L--;
			sum+=1ll*a[L]*(cnt[a[L]]*2+1);
			cnt[a[L]]++;
		}
		while(R>f[i].r){
			cnt[a[R]]--;
			sum-=1ll*a[R]*(cnt[a[R]]*2+1);
			R--;
		}
		while(L<f[i].l){
			cnt[a[L]]--;
			sum-=1ll*a[L]*(cnt[a[L]]*2+1);
			L++;
		}
		Ans[f[i].id]=sum;
	}
	for(i=1;i<=q;i++)
		printf("%lld\n",Ans[i]);
}
int main(){
	init();
	work();
	return 0;
}