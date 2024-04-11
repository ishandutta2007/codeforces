#include<cstdio>
typedef long long LL;
const int N=3e5+5;
int n,k;
LL b[N];
LL sum[N<<2],tag[N<<2];
inline LL Read(){
	char ch;
	int f=1;
	while((ch=getchar())<'0'||ch>'9')
		if(ch=='-') f=-1;
	LL x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x*f;
}
inline void print(const LL x){
	if(x>=10) print(x/10);
	putchar(x%10+48);
	return ;
}
inline void Print(const LL x,const char ch='\n'){
	if(x<0){
		putchar('-');
		print(-x);
	}
	else print(x);
	putchar(ch);
	return ;
}
inline void Add(const int u,const int ll,const int rr,const LL value){
	tag[u]+=value;
	sum[u]+=value*(rr-ll+1);
	return ;
}
inline void PushDown(const int u,const int ll,const int rr){
	int mid=ll+rr>>1;
	Add(u<<1,ll,mid,tag[u]);
	Add(u<<1|1,mid+1,rr,tag[u]);
	tag[u]=0;
	return ;
}
inline void Update(const int u){
	sum[u]=sum[u<<1]+sum[u<<1|1];
	return ;
}
inline void Modify(const int u,const int ll,const int rr,const int ql,const int qr,const LL value){
	if(ll>=ql&&rr<=qr) return Add(u,ll,rr,value);
	PushDown(u,ll,rr);
	int mid=ll+rr>>1;
	if(mid>=ql) Modify(u<<1,ll,mid,ql,qr,value);
	if(mid<qr) Modify(u<<1|1,mid+1,rr,ql,qr,value);
	return Update(u);
}
inline LL Query(const int u,const int ll,const int rr,const int ql,const int qr){
	if(ll>=ql&&rr<=qr) return sum[u];
	PushDown(u,ll,rr);
	int mid=ll+rr>>1;
	LL ss=0;
	if(mid>=ql) ss+=Query(u<<1,ll,mid,ql,qr);
	if(mid<qr) ss+=Query(u<<1|1,mid+1,rr,ql,qr);
	return ss;
}
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline int Min(const int x,const int y){
	return x<y?x:y;
}
LL ans;
inline void Solve(){
	for(register int i=n;i>=1;i--){
		LL now=Query(1,1,n,1,i);
		if(now>=b[i]) continue ;
		LL x=b[i]-now;
		int kk=Min(i,k);
		if(x%kk==0) x/=kk;
		else x=x/kk+1;
		ans+=x;
		Modify(1,1,n,Max(1,i-k+1),i,x);
	}
	Print(ans);
	return ;
}
inline void Init(){
	n=Read();k=Read();
	for(register int i=1;i<=n;i++)
		b[i]=Read();
	return ;
}
int main(){
	Init();
	Solve();
	return 0;
}