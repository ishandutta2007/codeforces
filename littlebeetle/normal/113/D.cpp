#include<cstdio>
const int N=502;
double eps=1e-10;
int n,m,A,B,i,j,a,b,c,d,p1,p2,cnt,k,id[N][N],deg[N],h[N],t[N],v[N];
double x[N][N],p[N],T;
void init(){
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
				id[i][j]=++cnt;
	while(m--){
		scanf("%d%d",&a,&b);
		deg[a]++;deg[b]++;
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	for(i=1;i<=n;i++)
		scanf("%lf",p+i);
	for(i=1;i<=n*n;i++){
		a=(i-1)/n+1;
		b=(i-1)%n+1;
		x[i][i]=1;
		if(a!=b)
			x[i][i]-=p[a]*p[b];
		for(p1=h[a];p1;p1=t[p1])
			for(p2=h[b];p2;p2=t[p2]){
				c=v[p1];
				d=v[p2];
				if(c!=d)
				x[i][id[c][d]]-=(1-p[c])*(1-p[d])/deg[c]/deg[d];
			}
		for(p1=h[a];p1;p1=t[p1]){
			c=v[p1];
			if(c!=b)
			x[i][id[c][b]]-=(1-p[c])/deg[c]*p[b];
		}
		for(p2=h[b];p2;p2=t[p2]){
			d=v[p2];
			if(a!=d)
			x[i][id[a][d]]-=p[a]*(1-p[d])/deg[d];
		}
	}
	x[id[A][B]][n*n+1]=1;
}
double abs(double x){
	return x>0?x:-x;
}
void swap(double &x,double &y){
	double t=y;y=x;x=t;
}
void work(int n){
	for(i=1;i<n;i++){
		for(j=i;abs(x[j][i])<eps;j++);
		if(j!=i)
			for(k=i;k<=n+1;k++)
				swap(x[i][k],x[j][k]);
		for(j=i+1;j<=n;j++){
			T=x[j][i]/x[i][i];
			for(k=i;k<=n+1;k++)
				x[j][k]-=x[i][k]*T;
		}
	}
	for(i=n;i>1;i--)
		for(j=i-1;j;j--){
			T=x[j][i]/x[i][i];
			x[j][i]-=T*x[i][i];
			x[j][n+1]-=x[i][n+1]*T;
		}
}
int main(){
	init();
	work(id[n][n]);
	for(i=1;i<=n;i++){
		j=id[i][i];
		printf("%.10lf ",x[j][n*n+1]/x[j][j]);
	}
	//while(1);
}