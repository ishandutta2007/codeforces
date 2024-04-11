#include<cstdio>
#include<ctime>
#include<algorithm>
using namespace std;
const int N=400002;
typedef long long ll;
int n,i,a,rt;
ll s[N],t,ans;
struct Treap{
	int sz[N],L[N],R[N],key[N],cnt;
	ll val[N];
	void Pushup(int x){
		sz[x]=sz[L[x]]+sz[R[x]]+1;
	}
	void RRotate(int &rt){
		int y=L[rt];
		L[rt]=R[y];
		R[y]=rt;
		Pushup(rt);
		rt=y;
		Pushup(rt);
	}
	void LRotate(int &rt){
		int y=R[rt];
		R[rt]=L[y];
		L[y]=rt;
		Pushup(rt);
		rt=y;
		Pushup(rt);
	}
	void Insert(int &rt,ll x){
		if(rt==0){
			rt=++cnt;
			val[rt]=x;
			sz[rt]=1;
			key[rt]=rand();
			return;
		}
		sz[rt]++;
		if(x<=val[rt]){
			Insert(L[rt],x);
			if(key[L[rt]]>key[rt])
				RRotate(rt);
		}
		else{
			Insert(R[rt],x);
			if(key[R[rt]]>key[rt])
				LRotate(rt);
		}
	}
	void Query(int rt,ll x){
		if(!rt)return;
		if(val[rt]>x){
			ans+=sz[R[rt]]+1;
			Query(L[rt],x);
		}
		else{
			Query(R[rt],x);
		}
	}
}T;
void init(){
	scanf("%d%lld",&n,&t);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[i]=s[i-1]+a;
	}
}
void work(){
	srand((unsigned)time(NULL));
	for(i=1;i<=n;i++){
		T.Insert(rt,s[i-1]);
		T.Query(rt,s[i]-t);
	}
	printf("%lld",ans);
}
int main(){
	init();
	work();
	return 0;
}