#include<cstdio>
const int N=18;
typedef long long ll;
ll f[1<<N][N],c[N][N],a[N],Ans;
int n,m,p,i,j,k,x,y,z,cnt[1<<N],t[1<<N];
//x--,y--
void init(){
	scanf("%d%d%d",&n,&m,&p);
	for(i=0;i<n;i++)
		scanf("%lld",a+i),t[1<<i]=i;
	while(p--){
		scanf("%d%d%d",&x,&y,&z);
		x--;y--;c[x][y]=z;
	}	
}
ll max(ll x,ll y){
	return x>y?x:y;
}
void dp(){
	for(i=1;i<(1<<n);i++){
		cnt[i]=cnt[i-(i&-i)]+1;
		if(cnt[i]>m)continue;
		if(cnt[i]==1){
			f[i][t[i]]=a[t[i]];
			if(cnt[i]==m)
				Ans=max(Ans,f[i][t[i]]=a[t[i]]);
			}
		else{
			for(j=0;j<n;j++)
				if(i>>j&1){
					for(k=0;k<n;k++)
						if(i>>k&1)
							if(j!=k)
								f[i][j]=max(f[i^1<<j][k]+a[j]+c[k][j],f[i][j]);
					if(cnt[i]==m)
						Ans=max(Ans,f[i][j]);
				}
		}
	}
	printf("%lld",Ans);
}
int main(){
	init();
	dp();
	//while(1);
	return 0;
}