#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2002,K=12;
struct Uzi{
	int a[K],Max;
	bool operator<(const Uzi &k)const{
		return k.Max<Max;
	}
}p[N];
int T,n,m,t,i,j,k,g[1<<K],f[1<<K],s;
void init(){
	scanf("%d%d",&m,&n);
	memset(p,0,sizeof(p));
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	for(j=0;j<m;j++)
		for(i=1;i<=n;i++){
			scanf("%d",&p[i].a[j]);
			p[i].Max=max(p[i].Max,p[i].a[j]);
		}
	sort(p+1,p+n+1);
	for(t=1;t<=n&&t<=m;t++){
		memset(g,0,sizeof(g));
		for(i=1;i<(1<<m);i++)
			for(j=0;j<m;j++){
				s=0;
				for(k=0;k<m;k++)
					if(i>>k&1)
						s+=p[t].a[(j+k)%m];
				g[i]=max(g[i],s);
			}
		for(i=(1<<m)-1;i>=0;i--)
			for(j=1;j<(1<<m);j++)
				if(i&j)
					j=j+(j&-j)-1;
				else
					f[i^j]=max(f[i^j],g[j]+f[i]);
	}
	printf("%d\n",f[(1<<m)-1]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		//work();
	}
	//while(1);
	return 0;
}