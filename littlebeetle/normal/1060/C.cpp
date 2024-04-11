#include<cstdio>
const int N=2002,M=4000002;
int n,m,i,j,k,a[N],b[N],sb[N],f[M],s,x,p,y,ans;
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=m;i++)
		scanf("%d",b+i),sb[i]=sb[i-1]+b[i];
	scanf("%d",&p);
	for(i=0;i<m;i++)
		for(j=i+1;j<=m;j++)
			f[sb[j]-sb[i]]=max(f[sb[j]-sb[i]],j-i);
	for(i=1;i<M;i++)
		f[i]=max(f[i],f[i-1]);
	for(i=0;i<n;i++){
		s=0;
		for(j=i+1;j<=n;j++){
			s+=a[j];
			x=p/s;
			if(x<M)
				y=f[x];
			else
				y=f[M-1];
			ans=max(ans,y*(j-i));
		}
	}
	printf("%d",ans);
	//while(1);
}