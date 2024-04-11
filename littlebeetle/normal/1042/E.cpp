#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1002,M=998244353;
struct p{
	ll x,y,v;
	bool operator<(const p &k)const{
		return k.v>v;
	}
}a[N*N];
int n,m,i,j,k,t,v,r,c,x,y;
ll f[N][N],S,sx,sy,sX,sY;
ll inv(ll x){
	ll s=1,b=M-2;
	while(b){
		if(b&1)
			s=s*x%M;
		b>>=1;
		x=x*x%M;
	}
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&v),
			a[++t]=(p){i,j,v};
	scanf("%d%d",&r,&c);
	sort(a+1,a+t+1);
	
	for(i=1;i<=t;i=j){
		for(j=i;a[j].v==a[i].v;j++)
			if(i!=1){
				x=a[j].x;y=a[j].y;
				f[x][y]=(((S+sX+sY-2*x*sx%M-2*y*sy%M)*inv(i-1)+x*x+y*y)%M+M)%M;
			}
		for(k=i;k<j;k++){
			x=a[k].x;y=a[k].y;
			S=(S+f[x][y])%M;
			sX=(sX+x*x)%M;
			sY=(sY+y*y)%M;
			sx+=x;
			sy+=y;
		}
	}
	printf("%lld",f[r][c]);
}