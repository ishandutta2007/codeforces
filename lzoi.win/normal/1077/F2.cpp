#include<cstdio>
typedef long long LL;
const int N=5005;
int q[N],head,tail;
LL f[N][N],ans;
inline int Read(){
	char ch;
	while((ch=getchar())<'0'||ch>'9');
	int x=ch^48;
	while((ch=getchar())>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
inline void push(const int m,const int i){
	while(head<=tail&&f[m][q[tail]]<f[m][i]) tail--;
	q[++tail]=i;
	return ;
}
int a[N];
int n,m,k;
inline void Init(){
	n=Read();
	k=Read();
	m=Read();
	for(register int i=1;i<=n;i++)
		a[i]=Read();
	for(register int i=1;i<=k;i++)
		f[1][i]=a[i];
	for(register int i=k+1;i<=n;i++)
		f[1][i]=-1;
	return ;
}
inline void Work(const int now){
	head=1,tail=0;
	if(f[now-1][now-1]!=-1) push(now-1,now-1);
	for(register int i=1;i<=now-1;i++) f[now][i]=-1;
	for(register int i=now;i<=n;i++){
		while(head<=tail&&i-q[head]>k) head++;
		if(head<=tail) f[now][i]=f[now-1][q[head]]+a[i];
		else f[now][i]=-1;
		if(f[now-1][i]!=-1) push(now-1,i);
	}
	return ;
}
inline LL Max(const LL x,const LL y){
	return x>y?x:y;
}
int main(){
	Init();
	for(register int i=2;i<=m;i++)
		Work(i);
	ans=-1;
	for(register int i=n-k+1;i<=n;i++)
		ans=Max(ans,f[m][i]);
	printf("%lld\n",ans);
	return 0;
}