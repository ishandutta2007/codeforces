#include<cstdio>
const int N=1000020;
const int M=1000000007;
typedef long long ll;
int n,i,j,k,a,b,h[N],t[N],v[N],fa[N],g[N];
ll f[N][2],s,p;
char ch;
void read(int &a){
	a=0;
	while((ch=getchar())<48);
	while(ch>47)
		a=a*10+ch-48,ch=getchar();
}
ll inv(ll x){
	s=1;p=M-2;
	while(p){
		if(p&1)
			s=s*x%M;
		x=x*x%M;
		p>>=1;
	}
	return s;
}
void dfs(int i){
	int j;
	if(g[i]){
		f[i][1]=1;
		for(j=h[i];j;j=t[j]){
			dfs(v[j]);
			f[i][1]=f[i][1]*(f[v[j]][0]+f[v[j]][1])%M;
		}
	}
	else{
		f[i][0]=1;
		for(j=h[i];j;j=t[j]){
			dfs(v[j]);
			f[i][0]=f[i][0]*(f[v[j]][0]+f[v[j]][1])%M;
		}		
		for(j=h[i];j;j=t[j])
			f[i][1]=(f[i][1]+f[i][0]*inv(f[v[j]][0]+f[v[j]][1])%M*f[v[j]][1])%M;
	}
}
int main(){
	read(n);
	for(b=1;b<n;b++){
		read(a);
		t[++k]=h[a];h[a]=k;v[k]=b;
	}
	for(i=0;i<n;i++)
		read(g[i]);
	dfs(0);
	printf("%lld",f[0][1]);
	return 0;	
}