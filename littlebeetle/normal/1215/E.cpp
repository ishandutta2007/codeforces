#include<cstdio>
#include<cstring>
using namespace std;
const int N=400002,M=20;
typedef long long ll;
int n,i,j,k,x,y,a[N],s[N];
ll cnt[M][M],f[1<<M],sum;
ll min(ll x,ll y){
	return x<y?x:y;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]--;
	}
}
ll Query(int x,int y){
	memset(s,0,sizeof(s));
	sum=0;
	for(i=1;i<=n;i++){
		s[i]=s[i-1];
		if(a[i]==y)
			s[i]++;
		if(a[i]==x)
			sum+=s[i];
	}
	return sum;
}
void pre(){
	for(x=0;x<M;x++)
		for(y=0;y<M;y++)
			if(x!=y)
				cnt[x][y]=Query(x,y);
}
void work(){
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(i=0;i<(1<<M);i++){
		for(j=0;j<M;j++)
			if(~i>>j&1){
				sum=f[i];
				for(k=0;k<M;k++)
					if(k!=j){
						if(i>>k&1)
							sum+=cnt[k][j];
						else
							sum+=cnt[j][k];
					}
				f[i^1<<j]=min(f[i^1<<j],sum);
			}
	}
	printf("%lld",f[(1<<M)-1]>>1);
}
int main(){
	init();
	pre();
	work();
	return 0;
}