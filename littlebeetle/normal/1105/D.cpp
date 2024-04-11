#include<cstdio>
const int P=9,N=1001,dx[]={1,-1,0,0},dy[]={0,0,1,-1};
struct p{
	int x,y;
}q[P][N*N];
int n,m,k,i,j,o,a[P],s[P],e[P],sum[P],tmp,u,v,x,y,g,L[N*N];
char c[N][N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<k;i++)
		scanf("%d",a+i),e[i]=-1;
	for(i=1;i<=n;i++){
		scanf("%s",c[i]+1);
		for(j=1;j<=m;j++)
			if(c[i][j]>='1'&&c[i][j]<='9'){
				o=c[i][j]-49;
				sum[o]++;
				q[o][++e[o]]=(p){i,j};
			}
	}
	while(tmp!=(1<<k)-1){
		for(o=0;o<k;o++){
			for(i=s[o];i<=e[o];i++)
				L[i]=0;
			for(i=s[o];i<=e[o];i++){
				if(L[i]>=a[o])
					break;
				u=q[o][i].x;
				v=q[o][i].y;
				for(g=0;g<4;g++){
					x=u+dx[g];
					y=v+dy[g];
					if(c[x][y]=='.'){
						c[x][y]=o+49;
						sum[o]++;
						q[o][++e[o]]=(p){x,y};
						L[e[o]]=L[i]+1;
					}
				}
			}
			s[o]=i;                                                                                               
			if(s[o]>e[o])
				tmp|=1<<o;
		}
	}
	for(i=0;i<k;i++)
		printf("%d\n",sum[i]);
}