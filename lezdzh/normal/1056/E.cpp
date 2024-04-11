#include<cstdio>
#include<cstring>
using namespace std;

const int md=481598279;
int p[1000001],w[1000001];
char c[100010],s[1000010];
int n,m;
int cx(int l,int r){
	return((w[r]-1ll*w[l-1]*p[r-l+1])%md+md)%md;
}
int pd(int u,int v){
	int o0=-1,o1=-1;
	int z=0;
	for(int i=1;i<=n;i++)
		if(c[i]=='0'){
			if(o0==-1)o0=z;
			else if(cx(z+1,z+u)!=cx(o0+1,o0+u))
				return 0;
			z+=u;
		}
		else{
			if(o1==-1)o1=z;
			else if(cx(z+1,z+v)!=cx(o1+1,o1+v))
				return 0;
			z+=v;
		}
	return u!=v||cx(o0+1,o0+u)!=cx(o1+1,o1+v);
}
int main(){
	scanf("%s%s",c+1,s+1);
	n=strlen(c+1),m=strlen(s+1);
	for(int i=p[0]=1;i<=m;i++)
		p[i]=1ll*p[i-1]*10007%md,
		w[i]=(1ll*w[i-1]*10007+s[i])%md;
	if(c[1]=='1')
		for(int i=1;i<=n;i++)
			c[i]=97-c[i];
	int gs0=0,gs1=0;
	for(int i=1;i<=n;i++)
		if(c[i]=='1')gs1++;
		else gs0++;
	int ans=0;
	if(gs0>gs1){
		if(!gs1)
			ans=m%gs0==0&&cx(1,m-m/gs0)==cx(m/gs0+1,m);
		else for(int i=1;i*gs0<m;i++)
			if((m-i*gs0)%gs1==0)
				ans+=pd(i,(m-i*gs0)/gs1);
	}
	else{
		for(int i=1;i*gs1<m;i++)
			if((m-i*gs1)%gs0==0)
				ans+=pd((m-i*gs1)/gs0,i);
	}
	printf("%d\n",ans);
}