#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

struct dn{int x,y;}a[100001],b[100001];
dn operator-(dn u,dn v){
	return(dn){u.x-v.x,u.y-v.y};
}
long long operator*(dn u,dn v){
	return 1ll*u.x*v.y-1ll*v.x*u.y;
}
long long cd(dn u,dn v){
	return 1ll*u.x*v.x+1ll*u.y*v.y;
}
bool cmp(dn u,dn v){
	return u.x^v.x?u.x<v.x:u.y<v.y;
}
struct da{long long l;double a;}x[200001],y[400001];
bool operator==(da u,da v){
	return u.l==v.l&&abs(u.a-v.a)<1e-10;
}
int s[100001],ss[100001];
int f[100001];
int main(){
	int n,m,nn,mm;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+m+1,cmp);
	s[s[0]=1]=1;
	for(int i=1;i<=n;i++){
		for(;s[0]>1&&(a[i]-a[s[s[0]-1]])*(a[s[s[0]]]-a[s[s[0]-1]])<=0;s[0]--);
		s[++s[0]]=i;
	}
	ss[ss[0]=1]=1;
	for(int i=1;i<=n;i++){
		for(;ss[0]>1&&(a[i]-a[ss[ss[0]-1]])*(a[ss[ss[0]]]-a[ss[ss[0]-1]])>=0;ss[0]--);
		ss[++ss[0]]=i;
	}
	for(int i=ss[0]-1;i>1;i--)
		s[++s[0]]=ss[i];
	for(int i=1;i<=s[0];i++){
		dn u=a[s[i]],v=a[s[i%s[0]+1]],w=a[s[(i+s[0]-2)%s[0]+1]];
		x[i]=(da){cd(u-v,u-v),1.0*cd(v-u,w-u)*cd(v-u,w-u)/(1.0*cd(v-u,v-u)*cd(w-u,w-u))};
	}
	nn=s[0];
	s[s[0]=1]=1;
	for(int i=1;i<=m;i++){
		for(;s[0]>1&&(b[i]-b[s[s[0]-1]])*(b[s[s[0]]]-b[s[s[0]-1]])<=0;s[0]--);
		s[++s[0]]=i;
	}
	ss[ss[0]=1]=1;
	for(int i=1;i<=m;i++){
		for(;ss[0]>1&&(b[i]-b[ss[ss[0]-1]])*(b[ss[ss[0]]]-b[ss[ss[0]-1]])>=0;ss[0]--);
		ss[++ss[0]]=i;
	}
	for(int i=ss[0]-1;i>1;i--)
		s[++s[0]]=ss[i];
	for(int i=1;i<=s[0];i++){
		dn u=b[s[i]],v=b[s[i%s[0]+1]],w=b[s[(i+s[0]-2)%s[0]+1]];
		y[i]=(da){cd(u-v,u-v),1.0*cd(v-u,w-u)*cd(v-u,w-u)/(1.0*cd(v-u,v-u)*cd(w-u,w-u))};
	}
	mm=s[0];
	for(int i=mm+1;i<=2*mm;i++)
		y[i]=y[i-mm];
	for(int i=2;i<=nn;i++){
		int j=f[i-1];
		while(j&&!(x[i]==x[j+1]))j=f[j];
		f[i]=j+(x[i]==x[j+1]);
	}
	bool ok=0;
	for(int i=1,j=0;i<=2*mm;i++){
		if(j==nn){ok=1;break;}
		while(j&&!(y[i]==x[j+1]))j=f[j];
		j+=y[i]==x[j+1];
		if(j==nn){ok=1;break;}
	}
	printf(ok?"YES\n":"NO\n");
}