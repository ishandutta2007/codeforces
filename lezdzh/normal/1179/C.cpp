#include<cstdio>
#include<algorithm>
using namespace std;

int a[300001],b[300001],h=1<<20,c[3000001],s[3000001];
void xg(int p,int z){
	p+=h;
	c[p]=s[p]+=z;
	for(p>>=1;p;p>>=1){
		s[p]=s[p<<1]+s[p<<1|1];
		c[p]=min(c[p<<1|1],s[p<<1|1]+c[p<<1]);
	}
}
int cx(){
	int o=1,w=0;
	for(;o<h;){
		if(c[o<<1|1]<w)o=o<<1|1;
		else w-=s[o<<1|1],o=o<<1;
	}
	return o==h?-1:o-h;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		xg(a[i],-1);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
		xg(b[i],1);
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int o,p,x;
		scanf("%d%d%d",&o,&p,&x);
		if(o==1){
			xg(a[p],1);
			a[p]=x;
			xg(a[p],-1);
		}
		else{
			xg(b[p],-1);
			b[p]=x;
			xg(b[p],1);
		}
		printf("%d\n",cx());
	}
}