#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000020;
struct d{
	int l,r;
	bool operator<(const d &x)const{
		return x.r>r;
	}
}a[N];
struct p{
	int id,L,R;
	bool operator<(const p &x)const{
		return x.R>R;
	}
}b[N];
int n,m,i,j,k,o,s[N],c[N],t;
void add(int x){
	while(x)
		c[x]++,x-=x&-x;
}
void sum(int x,int i){
	while(x<N)
		s[i]+=c[x],x+=x&-x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++){
		scanf("%d",&j);
		k=0;
		while(j--){
			scanf("%d",&o);
			if(k+1<o)
				b[++t]=(p){i,k+1,o-1};
			k=o;
		}
		b[++t]=(p){i,k+1,N-1};
	}
	sort(b+1,b+t+1);
	for(i=j=1;i<=t;i++){
		while(j<=n&&a[j].r<=b[i].R)
			add(a[j++].l);
		sum(b[i].L,b[i].id);
	}
	for(i=1;i<=m;i++)
		printf("%d\n",n-s[i]);
	return 0;
}