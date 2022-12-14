#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define rpd(i,r,l) for(int i=r;i>=l;i--)
#define N 305
int n,nn,l[N],c[N];
int tot,k,pr[233],va[N];
int m,ans,f[N][512];
void gmn(int &a,int b){
	if(b<a) a=b;
}
int main(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d",&l[i]);
	rpt(i,1,n) scanf("%d",&c[i]);
	ans=1<<30;
	rpt(i,1,n){
		tot=0;k=2;nn=l[i];
		while(nn>1){
			if(k*k>nn){
				pr[++tot]=nn;
				break;
			}
			if(nn%k==0){
				pr[++tot]=k;
				while(nn%k==0) nn/=k;
			}
			k++;
		}
		va[i]=m=(1<<tot)-1;
		rpt(j,i+1,n){
			va[j]=0;
			rpt(t,1,tot) if(l[j]%pr[t]==0) va[j]+=1<<(t-1);
		}
		rpt(j,i,n) rpt(t,0,m) f[j][t]=1<<30;
		f[i][m]=c[i];
		rpt(j,i,n-1) rpt(t,0,m){
			gmn(f[j+1][t],f[j][t]);
			gmn(f[j+1][t&va[j+1]],f[j][t]+c[j+1]);
		}
		gmn(ans,f[n][0]);
	}
	if(ans==1<<30) printf("-1");
	else printf("%d",ans);
}