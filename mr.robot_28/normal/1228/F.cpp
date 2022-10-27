#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=400002;
int n,nod,m,i,j,k,a,b;
int h[N],t[N],v[N];
int sz[N],mxsz[N],Mx,p,tmp,x[N];
int Ans[N],cnt,deg[N];
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d",&n);
	nod=(1<<n)-2;
	m=(1<<n)-3;
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
}
int max(int x,int y){
	return x>y?x:y;
}
void dfs1(int i,int fa){
	sz[i]=1;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs1(v[j],i);
			sz[i]+=sz[v[j]];
			mxsz[i]=max(mxsz[i],sz[v[j]]);
		}
	mxsz[i]=max(mxsz[i],nod-sz[i]);
}
void dfs2(int i,int fa){
	int j;
	
	for(j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs2(v[j],i);
			deg[i]++;
		}
	if(deg[i]==0){
		sz[i]=1;
		return;
	}
	//if(deg[i]>3)
	//	tmp=0;
	k=0;
	for(j=h[i];j;j=t[j])
		if(v[j]!=fa)
			x[++k]=sz[v[j]];
	sort(x+1,x+k+1);
	//printf("   %d %d\n",k,x[1]);
	if(k==1){
		if(x[1]!=1)
			tmp=0;
		p=i;
		sz[i]=3;
	}
	if(k==2){
		if(x[1]!=x[2])
			tmp=0;
		sz[i]=x[1]+x[2]+1;
	}
	if(k==3){
		if(x[1]+x[2]+1!=x[3])
			tmp=0;
		p=i;
		sz[i]=x[3]*2+1;
	}
}
void work(int root){
	memset(sz,0,sizeof(sz));
	memset(deg,0,sizeof(deg));
	tmp=1;
	p=0;
	dfs2(root,0);
	if(sz[root]!=nod+1)
		tmp=0;
	if(tmp)
		Ans[++cnt]=p;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	init();
	dfs1(1,0);
	Mx=1<<30;
	for(i=1;i<=nod;i++)
		Mx=min(Mx,mxsz[i]);
	for(i=1;i<=nod;i++){
 
		if(mxsz[i]==Mx){
			//		printf("%d\n",i);
			work(i);
		}
		}
	sort(Ans+1,Ans+cnt+1);
	n=0;
	for(i=1;i<=cnt;i++)
		if(Ans[i]!=Ans[i-1])
			n++;
	printf("%d\n",n);
	for(i=1;i<=cnt;i++)
		if(Ans[i]!=Ans[i-1])
			printf("%d ",Ans[i]);
	//while(1);
 
}