#include<cstdio>
typedef long long LL;
const int N=2e5+5;
const int Z=2;
int n,T;
LL f[N][Z],g[N][Z];
int viss[N];
char s[N][Z];
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
inline int Max(const int x,const int y){
	return x>y?x:y;
}
inline LL Min(const LL x,const LL y){
	return x<y?x:y;
}
inline void Init(){
	n=Read();
	for(int i=1;i<=n;i++)
		while((s[i][0]=getchar())!='.'&&s[i][0]!='*');
	for(int i=1;i<=n;i++)
		while((s[i][1]=getchar())!='.'&&s[i][1]!='*');
	for(int i=1;i<=n;i++){
		f[i][0]=f[i][1]=1ll*N*N;
		g[i][0]=g[i][1]=1ll*N*N;
	}
	return ;
}
inline void Solve(){
	f[0][0]=f[0][1]=0;
	g[n+1][0]=g[n+1][1]=0;
	bool vis=0;
	for(int i=1;i<=n;i++){
		if(!vis){
			f[i][0]=f[i][1]=0;
			if(s[i][0]=='*') f[i][1]++;
			if(s[i][1]=='*') f[i][0]++;
		}
		else{
			if(s[i][0]=='*'&&s[i][1]=='*')
				f[i][1]=f[i][0]=Min(f[i-1][0]+2,f[i-1][1]+2);
			else if(s[i][0]=='*'){
				f[i][0]=Min(f[i-1][0]+1,f[i-1][1]+2);
				f[i][1]=Min(f[i-1][0]+2,f[i-1][1]+2);
			}
			else if(s[i][1]=='*'){
				f[i][0]=Min(f[i-1][0]+2,f[i-1][1]+2);
				f[i][1]=Min(f[i-1][0]+2,f[i-1][1]+1);
			}
			else{
				f[i][0]=Min(f[i-1][0]+1,f[i-1][1]+2);
				f[i][1]=Min(f[i-1][0]+2,f[i-1][1]+1);
			}
		}
		if(s[i][0]=='*'||s[i][1]=='*') vis=1;
	}
	vis=0;
	for(int i=n;i;i--){
		if(!vis){
			g[i][0]=g[i][1]=0;
			if(s[i][0]=='*') g[i][1]++;
			if(s[i][1]=='*') g[i][0]++;
		}
		else{
			if(s[i][0]=='*'&&s[i][1]=='*')
				g[i][1]=g[i][0]=Min(g[i+1][0]+2,g[i+1][1]+2);
			else if(s[i][0]=='*'){
				g[i][0]=Min(g[i+1][0]+1,g[i+1][1]+2);
				g[i][1]=Min(g[i+1][0]+2,g[i+1][1]+2);
			}
			else if(s[i][1]=='*'){
				g[i][0]=Min(g[i+1][0]+2,g[i+1][1]+2);
				g[i][1]=Min(g[i+1][0]+2,g[i+1][1]+1);
			}
			else{
				g[i][0]=Min(g[i+1][0]+1,g[i+1][1]+2);
				g[i][1]=Min(g[i+1][0]+2,g[i+1][1]+1);
			}
		}
		if(s[i][0]=='*'||s[i][1]=='*') vis=1;
	}
	for(int i=1;i<=n;i++){
		viss[i]=viss[i-1];
		if(s[i][0]=='*') viss[i]++;
		if(s[i][1]=='*') viss[i]++;
	}
	viss[n+1]=viss[n];
	/*puts("f");
	for(int i=1;i<=n;i++)
		printf("%lld %lld\n",f[i][0],f[i][1]);
	puts("g");
	for(int i=1;i<=n;i++)
		printf("%lld %lld\n",g[i][0],g[i][1]);*/
	LL ans=1ll*N*N;
	for(int i=0;i<=n;i++){
		if(viss[i]&&viss[i]<viss[n]){
			ans=Min(ans,f[i][0]+g[i+1][0]+1);
			ans=Min(ans,f[i][1]+g[i+1][0]+2);
			ans=Min(ans,f[i][0]+g[i+1][1]+2);
			ans=Min(ans,f[i][1]+g[i+1][1]+1);
		}
		else if(viss[i]){
			ans=Min(ans,f[i][0]);
			ans=Min(ans,f[i][1]);
		}
		else if(viss[i]<viss[n]){
			ans=Min(ans,g[i+1][0]);
			ans=Min(ans,g[i+1][1]);
		}
	}
	Print(ans);
	return ;
}
int main(){
	for(T=Read();T;T--){
		Init();
		Solve();
	}
	return 0;
}