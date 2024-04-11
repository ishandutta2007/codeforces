#include<bits/stdc++.h>
#define xxx 300100
#define yyy 600200
using namespace std;
int n,m,v1[xxx],sz1=0,v2[xxx],sz2=0;

int par[xxx];
int GF(int x){
	return par[x]==x?x:par[x]=GF(par[x]);
}

struct R{
	int to,nex;
}r[yyy];
int hea[xxx]={0},cnt=1;

int fa[xxx][22]={0},in[xxx][22]={0},pos[xxx],dep[xxx],ans,an[xxx]={0};
void dfs(int x,int f){
	dep[x]=dep[f]+1;
	fa[x][0]=f;
	for (int i=1;i<=20;i++){
		if (dep[x]>(1<<i)){
			fa[x][i]=fa[fa[x][i-1]][i-1];
		}else{
			break;
		}
	}
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to;
		if (y==f) continue;
		pos[y]=i>>1;
		dfs(y,x);
	}
}

void doit(int x,int y){
	if (dep[x]<dep[y]){
		swap(x,y);
	}
	for (int i=20;i>=0;i--){
		if (dep[x]-(1<<i)>=dep[y]){
			in[x][i]^=1;
			x=fa[x][i];
		}
	}
	if (x==y) return;
	for (int i=20;i>=0;i--){
		if (fa[x][i]!=fa[y][i]){
			in[x][i]^=1;
			x=fa[x][i];
			in[y][i]^=1;
			y=fa[y][i];
		}
	}
	in[x][0]^=1;in[y][0]^=1;
}

int main(){
	int x,y,px,py;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==1){
			v1[++sz1]=i;
		}if (x==-1){
			v2[++sz2]=i;
		}
		par[i]=i;
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		px=GF(x);py=GF(y);
		if (px==py) continue;
		par[px]=py;
		r[++cnt]=(R){y,hea[x]};
		hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]};
		hea[y]=cnt;
	}
	
	dep[0]=0;
	dfs(1,0);
	
	if (sz1&1){
		if (sz2==0){
			printf("-1");
			return 0;
		}else{
			v1[++sz1]=v2[1];
		}
	}
	
	for (int i=1;i*2<=sz1;i++){
		doit(v1[i*2-1],v1[i*2]);
	}
	
	for (int i=20;i>0;i--){
		for (int j=1;j<=n;j++){
			if (in[j][i]){
				in[j][i-1]^=1;
				in[fa[j][i-1]][i-1]^=1;
			}
		}
	}
	
	ans=0;
	for (int i=2;i<=n;i++){
		if (in[i][0]){
			ans++;
			an[pos[i]]=1;
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;i++){
		if (an[i]){
			printf("%d\n",i);
		}
	}
	return 0;
}