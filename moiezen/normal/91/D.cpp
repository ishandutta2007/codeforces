#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 100005
int n,a[N],vis[N];
int p,tot,l[N];
int m,x[N],y[N],z[N];
int k,u[N],v[N];
int ans,s[N],c[N][2][5];
int main(){
	scanf("%d",&n);
	rpt(i,1,n) scanf("%d",&a[i]),vis[i]=0;
	ans=m=k=0;
	rpt(i,1,n) if(!vis[i]){
		p=i;tot=0;
		while(!vis[p]) l[++tot]=p,vis[p]=1,p=a[p];
		while(tot>=4){
			if(tot==4){
				s[++ans]=4;
				rpt(i,0,3) c[ans][0][i]=l[i+1],c[ans][1][i]=a[l[i+1]];
				break;
			}
			s[++ans]=5;
			rpt(i,0,4) c[ans][0][i]=l[tot-i],c[ans][1][i]=a[l[tot-i]];
			c[ans][1][0]=l[tot-4];
			a[l[tot-4]]=a[l[tot]];
			tot-=4;
		}
		if(tot==2){
			++k;u[k]=l[1];v[k]=l[2];
		}
		if(tot==3){
			++m;x[m]=l[1];y[m]=l[2];z[m]=l[3];
		}
	}
	while(m||k){
		if(m==1&&k==0){
			s[++ans]=3;
			c[ans][0][0]=c[ans][1][2]=x[1];
			c[ans][0][1]=c[ans][1][0]=y[1];
			c[ans][0][2]=c[ans][1][1]=z[1];
			break;
		}
		if(m==0&&k==1){
			s[++ans]=2;
			c[ans][0][0]=c[ans][1][1]=u[1];
			c[ans][0][1]=c[ans][1][0]=v[1];
			break;
		}
		if(m>k){
			s[++ans]=5;
			c[ans][0][0]=c[ans][1][2]=x[m];
			c[ans][0][1]=c[ans][1][0]=y[m];
			c[ans][0][2]=c[ans][1][1]=z[m];
			m--;
			c[ans][0][3]=c[ans][1][4]=y[m];
			c[ans][0][4]=c[ans][1][3]=z[m];
			k++;
			u[k]=x[m];
			v[k]=y[m];
			m--;
		}
		else if(m){
			s[++ans]=5;
			c[ans][0][0]=c[ans][1][2]=x[m];
			c[ans][0][1]=c[ans][1][0]=y[m];
			c[ans][0][2]=c[ans][1][1]=z[m];
			m--;
			c[ans][0][3]=c[ans][1][4]=u[k];
			c[ans][0][4]=c[ans][1][3]=v[k];
			k--;
		}
		else{
			s[++ans]=4;
			c[ans][0][0]=c[ans][1][1]=u[k];
			c[ans][0][1]=c[ans][1][0]=v[k];
			k--;
			c[ans][0][2]=c[ans][1][3]=u[k];
			c[ans][0][3]=c[ans][1][2]=v[k];
			k--;
		}
	}
	printf("%d\n",ans);
	rpt(i,1,ans){
		printf("%d\n",s[i]);
		rpt(j,0,1){
			rpt(k,0,s[i]-1) printf("%d ",c[i][j][k]);
			printf("\n");
		}
	}
}