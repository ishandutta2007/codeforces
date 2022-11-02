#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=200002;
struct p{
	int l,r,x,id;
	bool operator<(const p &k)const{
		return k.x^x?k.x<x:(k.r<r)^(x&1);
	}
}q[N];
int n,m,k,i,x,a[N],L,R,s[N*10];
long long ans[N],S;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]^=a[i-1];
	}
	x=(int)(n/(sqrt(m)+1)+1);
	for(i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].x=--q[i].l/x;
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	L=q[1].l;R=q[1].l-1;
	for(i=1;i<=m;i++){
		while(R<q[i].r){
			S+=s[a[++R]^k];
			s[a[R]]++;
		}
		while(L>q[i].l){
			S+=s[a[--L]^k];
			s[a[L]]++;
		}
		while(R>q[i].r){
			s[a[R]]--;
			S-=s[a[R--]^k];
		}
		while(L<q[i].l){
			s[a[L]]--;
			S-=s[a[L++]^k];
		}
		ans[q[i].id]=S;
	}
	for(i=1;i<=m;i++)
		printf("%I64d\n",ans[i]);
}