#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+5;
const int block=1200;
int fal[N<<2][3],far[N<<2][3],ans[N<<2];
int n,q;
bool mp[N][3];
int fa[N*3];
inline int Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(const int x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const int x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Init(){
	n=Read();
	for(register int i=0;i<3;i++)
		for(register int j=1;j<=n;j++){
			char ch;
			while((ch=getchar())!='0'&&ch!='1');
			mp[j][i]=ch-'0';
		}
	return ;
}
inline int Find(const int u){
	return fa[u]==u?u:fa[u]=Find(fa[u]);
}
inline void Merge(const int u,const int v,int&ss){
	int fu=Find(u),fv=Find(v);
	//printf("u=%d %d v=%d %d\n",u,fu,v,fv);
	if(fu==fv) return ;
	fa[fu]=fv;
	ss--;
	return ;
}
inline void Update(const int u,const int ll,const int rr){
	int mid=ll+rr>>1;
	ans[u]=ans[u<<1]+ans[u<<1|1];
	if(mp[mid][0]&&mp[mid+1][0]) Merge(mid,mid+1,ans[u]);
	if(mp[mid][1]&&mp[mid+1][1]) Merge(mid+n,mid+1+n,ans[u]);
	if(mp[mid][2]&&mp[mid+1][2]) Merge(mid+2*n,mid+1+2*n,ans[u]);
	for(register int i=0;i<3;i++){
		fal[u][i]=Find(ll+i*n);
		far[u][i]=Find(rr+i*n);
	}
	//printf("%d %d %d\n",ll,rr,ans[u]);
	//getchar();
	return ;
}
inline void Build(const int u,const int ll,const int rr){
	if(ll==rr){
		ans[u]=mp[ll][0]+mp[ll][1]+mp[ll][2];
		//printf("n=%d %d %d %d %d %d %d\n",n,fa[ll],fa[ll+n],fa[ll+2*n],ll,ll+n,ll+2*n);
		//fa[ll]=ll;
		//printf("n=%d %d %d %d %d %d %d\n",n,fa[ll],fa[ll+n],fa[ll+2*n],ll,ll+n,ll+2*n);
		//fa[ll+n]=ll+n;
		//printf("n=%d %d %d %d %d %d %d\n",n,fa[ll],fa[ll+n],fa[ll+2*n],ll,ll+n,ll+2*n);
		//fa[ll+2*n]=ll+2*n;
		for(register int i=0;i<3;i++)
			fa[ll+i*n]=ll+i*n;
		//printf("n=%d %d %d %d %d %d %d\n",n,fa[ll],fa[ll+n],fa[ll+2*n],ll,ll+n,ll+2*n);
		if(mp[ll][1]&&mp[ll][0]) fa[ll+n]=ll,ans[u]--;
		if(mp[ll][2]&&mp[ll][1]) fa[ll+2*n]=ll+n,ans[u]--;
		//printf("%d %d %d\n",fa[ll],fa[ll+n],fa[ll+2*n]);
		for(register int i=0;i<3;i++)
			fal[u][i]=far[u][i]=Find(ll+i*n);
		//printf("%d %d %d %d %d %d\n",ll,rr,ans[u],Find(ll),Find(ll+n),Find(ll+2*n));
		//getchar();
		return ;
	}
	int mid=ll+rr>>1;
	Build(u<<1,ll,mid);
	Build(u<<1|1,mid+1,rr);
	return Update(u,ll,rr);
}
int qans;
inline void Get(const int u,const int ll,const int rr){
	qans+=ans[u];
	for(register int i=0;i<3;i++){
		fa[ll+i*n]=fal[u][i];
		fa[rr+i*n]=far[u][i];
	}
	if(ll<rr){
		if(fa[rr+2*n]==fa[rr+n]) fa[rr+2*n]=rr+n;
		else if(fa[rr+2*n]==fa[rr]) fa[rr+2*n]=rr;
		else if(fa[rr+2*n]==fa[ll+2*n]) fa[rr+2*n]=ll+2*n;
		else if(fa[rr+2*n]==fa[ll+n]) fa[rr+2*n]=ll+n;
		else if(fa[rr+2*n]==fa[ll]) fa[rr+2*n]=ll;
		else fa[rr+2*n]=rr+2*n;
		if(fa[rr+n]==fa[rr]) fa[rr+n]=rr;
		else if(fa[rr+n]==fa[ll+2*n]) fa[rr+n]=ll+2*n;
		else if(fa[rr+n]==fa[ll+n]) fa[rr+n]=ll+n;
		else if(fa[rr+n]==fa[ll]) fa[rr+n]=ll;
		else fa[rr+n]=rr+n;
		if(fa[rr]==fa[ll+2*n]) fa[rr]=ll+2*n;
		else if(fa[rr]==fa[ll+n]) fa[rr]=ll+n;
		else if(fa[rr]==fa[ll]) fa[rr]=ll;
		else fa[rr]=rr;
	}
	if(fa[ll+2*n]==fa[ll+n]) fa[ll+2*n]=ll+n;
	else if(fa[ll+2*n]==fa[ll]) fa[ll+2*n]=ll;
	else fa[ll+2*n]=ll+2*n;
	if(fa[ll+n]==fa[ll]) fa[ll+n]=ll;
	else fa[ll+n]=ll+n;
	fa[ll]=ll;
	if(qans==ans[u]) return ;
	if(mp[ll-1][0]&&mp[ll][0]) Merge(ll-1,ll,qans);
	if(mp[ll-1][1]&&mp[ll][1]) Merge(ll+n-1,ll+n,qans);
	if(mp[ll-1][2]&&mp[ll][2]) Merge(ll+2*n-1,ll+2*n,qans);
	return ;
}
inline void Query(const int u,const int ll,const int rr,const int ql,const int qr){
	if(ll>=ql&&rr<=qr) return Get(u,ll,rr);
	int mid=ll+rr>>1;
	if(mid>=ql) Query(u<<1,ll,mid,ql,qr);
	if(mid<qr) Query(u<<1|1,mid+1,rr,ql,qr);
	return ;
}
inline void Solve(){
	/*for(register int i=1;i<=n;i++){
		fa[i]=i;
		fa[i+n]=i+n;
		fa[i+2*n]=i+2*n;
		//printf("%d %d %d %d %d %d\n",i,i+n,i+2*n,fa[i],fa[i+n],fa[i+2*n]);
	}*/
	//return ;
	Build(1,1,n);
	for(q=Read();q;q--){
		int ql=Read(),qr=Read();
		qans=0;
		Query(1,1,n,ql,qr);
		Print(qans);
	}
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}