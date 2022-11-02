#include<cstdio>
#include<map>
using namespace std;
const int N=100002;
int n,p,q,w[N],i,j,k,l,r;
map<int,int>phi;
void Get(int x){
	if(x==1)return;
	int a=x,b=1,i;
	for(i=2;i*i<=a;i++)
		if(a%i==0){
			b*=(i-1);
			a/=i;
			while(a%i==0)
				a/=i,b*=i;
		}
	if(a!=1)
		b*=a-1;
	phi[x]=b;
	Get(b);
}
int ksm(int x,int b,int p){
	int s=1;
	while(b){
		if(b&1)
			s=1ll*s*x>=p?1ll*s*x%p+p:1ll*s*x;
		b>>=1;
		x=1ll*x*x>=p?1ll*x*x%p+p:1ll*x*x;
	}
	return s;
}
int solve(int l,int r,int p){
	if(l==r)return w[l]>=p?w[l]%p+p:w[l];
	if(p==1)return w[l]>=p?w[l]%p+p:w[l];
	
	return ksm(w[l],solve(l+1,r,phi[p]),p);
}
int main(){
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
		scanf("%d",w+i);
	Get(p);
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",solve(l,r,p)%p);
	}
}