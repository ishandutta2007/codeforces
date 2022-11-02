#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2000002;
struct P{
	int l,r,o,id;
}q[N];
int n,m,i,a[N],blk,s[N],ans,p[N],L,R;
bool cmp(P x,P y){
	return x.o!=y.o?x.o<y.o:x.r<y.r;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>n)
			a[i]=n+1;
	}
	blk=n/sqrt(m)+1;
	for(i=1;i<=m;i++){
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].o=q[i].l/blk;
		q[i].id=i;
	}
	sort(q+1,q+m+1,cmp);
	L=q[1].l;R=q[1].l-1;
	for(i=1;i<=m;i++){
		while(R<q[i].r){
			R++;
			ans-=s[a[R]]==a[R];
			s[a[R]]++;
			ans+=s[a[R]]==a[R];
		}
		while(L>q[i].l){
			L--;
			ans-=s[a[L]]==a[L];
			s[a[L]]++;
			ans+=s[a[L]]==a[L];
		}
		while(R>q[i].r){
			ans-=s[a[R]]==a[R];
			s[a[R]]--;
			ans+=s[a[R]]==a[R];
			R--;
		}
		while(L<q[i].l){
			ans-=s[a[L]]==a[L];
			s[a[L]]--;
			ans+=s[a[L]]==a[L];
			L++;
		}
		p[q[i].id]=ans;
	}
	for(i=1;i<=m;i++)
		printf("%d\n",p[i]);
}