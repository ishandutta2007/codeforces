#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000020,Inf=1<<30;
int n,m,i,j,k,a,b,c,d[N],u[N],v[N],w[N],ans[N],cnt,g[N];
struct LCT{
	int ch[N][2],fa[N],Max[N],id[N],st[N],top,lz1[N],lz2[N],val[N];
	bool Nroot(int x){
		return x==ch[fa[x]][1]||x==ch[fa[x]][0];
	}
	bool Get(int x){
		return x==ch[fa[x]][1];
	}
	void Swap(int &x,int &y){
		int t=x;x=y;y=t;
	}
	void Pushup(int x){
		Max[x]=id[x];
		if(w[Max[ch[x][0]]]>w[Max[x]])
			Max[x]=Max[ch[x][0]];
		if(w[Max[ch[x][1]]]>w[Max[x]])
			Max[x]=Max[ch[x][1]];
	}
	void Rotate(int x){
		int y=fa[x],z=fa[y],w=Get(x);
		fa[ch[y][w]=ch[x][w^1]]=y;
		if(Nroot(y))ch[z][Get(y)]=x;fa[x]=z;
		fa[ch[x][w^1]=y]=x;
		Pushup(y);
	}
	void Cover(int x,int y){
		if(x){
			lz2[x]=min(lz2[x],y);
			val[x]=min(val[x],y);
		}
	}
	void Change(int x){
		if(x){
			Swap(ch[x][0],ch[x][1]);
			lz1[x]^=1;
		}
	}
	void Pushdown(int x){
		if(lz1[x]){
			Change(ch[x][0]);
			Change(ch[x][1]);
			lz1[x]=0;
		}
		if(lz2[x]<(1<<30)){
			Cover(ch[x][0],lz2[x]);
			Cover(ch[x][1],lz2[x]);
			lz2[x]=1<<30;
		}
	}
	void Splay(int x){
		int y=x;
		st[top=1]=y;
		while(Nroot(y))st[++top]=y=fa[y];
		while(top)Pushdown(st[top--]);
		while(Nroot(x)){
			y=fa[x];
			if(Nroot(y))
				Rotate(Get(x)==Get(y)?y:x);
			Rotate(x);
		}
		Pushup(x);
	}
	void Access(int x){
		for(int y=0;x;x=fa[y=x])
			Splay(x),ch[x][1]=y,Pushup(x);
	}
	void Makeroot(int x){
		Access(x);
		Splay(x);
		Change(x);
	}
	int Findroot(int x){
		Access(x);
		Splay(x);
		while(ch[x][0]){
			Pushdown(x);
			x=ch[x][0];
		}
		Splay(x);
		return x;
	}
	void Split(int x,int y){
		Makeroot(x);
		Access(y);
		Splay(y);
	}
	int Link(int x,int y,int z){
		cnt++;
		Makeroot(x);
		Makeroot(y);
		fa[x]=fa[y]=cnt;
		id[cnt]=z;
		return cnt;
	}
	int Query(int x,int y){
		Split(x,y);
		return w[Max[y]];
	}
	int Query2(int x){
		Splay(x);
		return val[x];
	}
	bool Connected(int x,int y){
		return Findroot(x)==Findroot(y);
	}
	void Update(int x,int y,int z){
		Split(x,y);
		Cover(y,z);
	}
}T;
bool cmp(int x,int y){
	return w[x]<w[y];
}
void init(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for(i=1;i<=m;i++){
		scanf("%d%d%d",u+i,v+i,w+i);
		d[i]=i;
	}
	sort(d+1,d+m+1,cmp);
	for(i=0;i<N;i++)
		T.lz2[i]=T.val[i]=Inf;
}
void work(){
	for(i=1;i<=m;i++){
		k=d[i];
		a=u[k];b=v[k];c=w[k];
		if(T.Connected(a,b)){
			ans[k]=T.Query(a,b);
			T.Update(a,b,c);
		}
		else
			g[k]=T.Link(a,b,k);
	}
	for(i=1;i<=m;i++)
		if(!g[i])
			printf("%d ",ans[i]-1);
		else{
			k=T.Query2(g[i]);
			printf("%d ",k==Inf?-1:k-1);
		}
}
int main(){
	init();	
	work();
	//while(1);
	return 0;
}