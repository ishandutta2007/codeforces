#include<cstdio>
#include<algorithm>
#include<ctime>
using namespace std;
const int N=200002;
int n,a,c,k,i,id[N];
struct Treap{
	int root,val[N],sz[N],L[N],R[N],rnd[N],Max[N],cnt;
	int max(int x,int y){
		return x>y?x:y;
	}
	void Pushup(int rt){
		Max[rt]=max(val[rt],max(Max[L[rt]],Max[R[rt]]));
		sz[rt]=sz[L[rt]]+sz[R[rt]]+1;
	}
	void LRotate(int &rt){
		int y=R[rt];
		R[rt]=L[y];
		L[y]=rt;
		Pushup(rt);
		rt=y;
	}
	void RRotate(int &rt){
		int y=L[rt];
		L[rt]=R[y];
		R[y]=rt;
		Pushup(rt);
		rt=y;
	}
	void Insert(int &rt,int a,int k){
		if(!rt){
			rt=++cnt;
			val[rt]=Max[rt]=a;
			sz[rt]=1;
			rnd[rt]=rand();
			return;
		}
		if(k<=sz[L[rt]]){
			Insert(L[rt],a,k);
			if(rnd[L[rt]]<rnd[rt])
				RRotate(rt);
		}
		else{
			Insert(R[rt],a,k-sz[L[rt]]-1);
			if(rnd[R[rt]]<rnd[rt])
				LRotate(rt);
		}
		Pushup(rt);
	}
	int Query(int rt,int x){
		if(!rt)return 0;
		if(Max[L[rt]]>x)return Query(L[rt],x);
		if(val[rt]>x)return sz[L[rt]];
		return sz[L[rt]]+1+Query(R[rt],x);
	}
	void dfs(int rt){
		if(R[rt])dfs(R[rt]);
		printf("%d ",id[val[rt]]);
		if(L[rt])dfs(L[rt]);	
}
}T;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&c);
		id[a]=i;
		k=min(T.Query(T.root,a),c);
		T.Insert(T.root,a,k);
	}
	T.dfs(T.root);
}