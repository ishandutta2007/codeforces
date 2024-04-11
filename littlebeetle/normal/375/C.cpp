#include<cstdio>
#include<cstring>
using namespace std;
const int N=22,M=9,Q=2000000,Inf=1<<25;
const int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int n,m,i,j,k,val[N],lx[N],ly[N],cnt,u,v,x,y,z,px,py,pz;
char s[N][N];
int f[N][N][1<<M],qx[Q],qy[Q],qz[Q],p[1<<M],l,r,Ans;
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(j=1;j<=m;j++)
			if(s[i][j]>='1'&&s[i][j]<='9'){
				lx[s[i][j]-'1']=i;
				ly[s[i][j]-'1']=j;
				cnt++;
				s[i][j]--;
			}
	}
	for(i=0;i<cnt;i++)
		scanf("%d",val+i);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(s[i][j]=='B'){
				lx[cnt]=i;
				ly[cnt]=j;
				val[cnt]=-Inf;
				s[i][j]='0'+cnt;
				cnt++;
			}
			if(s[i][j]=='S'){
				u=i;v=j;
				s[i][j]='.';
			}
		}
	for(i=0;i<cnt;i++)
		p[1<<i]=val[i];
	for(j=0;j<cnt;j++)
		for(i=0;i<(1<<cnt);i++)
			if(i>>j&1)
				p[i]+=p[i^1<<j];
}
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int Chag(int z,int x,int y,int px,int py){
	if(x!=px)return z;
	for(int k=0;k<cnt;k++)
		if(lx[k]<x&&ly[k]>=min(y,py)&&ly[k]<max(y,py))
			z^=1<<k;
	return z;
}
void bfs(){
	memset(f,0x3f,sizeof(f));
	f[u][v][0]=0;
	qx[0]=u;qy[0]=v;qz[0]=0;
	while(l<=r){
		x=qx[l];y=qy[l];z=qz[l];
		l++;
		for(k=0;k<4;k++){
			px=x+dx[k];
			py=y+dy[k];
			if(s[px][py]=='.'){
				pz=Chag(z,x,y,px,py);
				if(f[px][py][pz]>f[x][y][z]+1){
					f[px][py][pz]=f[x][y][z]+1;
					r++;
					qx[r]=px;qy[r]=py;qz[r]=pz;
				}
			}
		}
	}
	for(i=0;i<(1<<cnt);i++)
		Ans=max(Ans,p[i]-f[u][v][i]);
	printf("%d",Ans);
	return;
}
int main(){
	init();
	bfs();
	return 0;
}