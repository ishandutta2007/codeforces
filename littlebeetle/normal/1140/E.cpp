#include<cstdio>
#include<cstring>
using namespace std;
const int N=200020,M=998244353;
typedef long long ll;
int n,k,m,i,a[N],b[N];
ll f[N],g[N];
void init(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
}
ll work1(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	m=0;
	for(i=1;i<=n;i+=2)
		b[++m]=a[i];
	if(b[1]==-1){
		b[1]=1;
		f[1]=1;
		g[1]=1;
	}
	else
		f[1]=1;
	for(i=2;i<=m;i++)
		if(b[i]==-1){
			b[i]=b[i-1];
			f[i]=g[i-1]*(k-1)%M;
			g[i]=(f[i-1]+g[i-1]*(k-2))%M;
		}
		else{
			if(b[i]==b[i-1])
				f[i]=g[i-1]*(k-1)%M;
			else
				f[i]=(f[i-1]+g[i-1]*(k-2))%M;
		}
	//printf("%lld %lld\n",f[m],g[m]);
	return (f[m]+g[m]*(k-1))%M;
}
ll work2(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	m=0;
	for(i=2;i<=n;i+=2)
		b[++m]=a[i];
	if(b[1]==-1){
		b[1]=1;
		f[1]=1;
		g[1]=1;
	}
	else
		f[1]=1;
	for(i=2;i<=m;i++)
		if(b[i]==-1){
			b[i]=b[i-1];
			f[i]=g[i-1]*(k-1)%M;
			g[i]=(f[i-1]+g[i-1]*(k-2))%M;
		}
		else{
			if(b[i]==b[i-1])
				f[i]=g[i-1]*(k-1)%M;
			else
				f[i]=(f[i-1]+g[i-1]*(k-2))%M;
		}
	//printf("%lld %lld\n",f[m],g[m]);
	return (f[m]+g[m]*(k-1))%M;
}
int main(){
	init();
	printf("%lld\n",work1()*work2()%M);
	//while(1);
}