#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=2e3+7,M=13;
struct node{
	int ch[M];
}k;
int T,n,m,ans,f[M][N],len[N];
std::vector<node>vet[N];
inline node max(const node &a,const node &b){
	static node res;
	for(int i=1;i<=n;i++)res.ch[i]=std::max(a.ch[i],b.ch[i]);
	return res;
}
inline node split(const node &a,int p){
	static node res; int len=0;
	for(int i=p;i<=n;i++)res.ch[++len]=a.ch[i];
	for(int i=1;i< p;i++)res.ch[++len]=a.ch[i];
	return res;
}
inline node solve(const node &a){
	int p=0;
	for(int i=1;i<=n;i++)if(a.ch[p]<a.ch[i])p=i;
	return split(a,p);
}
inline int check(const node &a,const node &b){
	int i,fl;
	for(i=fl=1;i<=n;i++)if(a.ch[i]>b.ch[i])fl=0;if(fl)return 2;
	for(i=fl=1;i<=n;i++)if(a.ch[i]<b.ch[i])fl=0;if(fl)return 1;
	return 0;
}
inline void append(int c,node w){
	for(int i=0;i<len[c];i++){
		int x=check(w,vet[c][i]);
		if(x==2)return;
		if(x==1){vet[c][i]=w;return;}
	}
	len[c]++,vet[c].push_back(w);
}
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(T);
	while(T--){
		read(n),read(m),ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)read(f[i][j]);
		len[0]=1,vet[0].push_back(k);
		for(int i=1;i<=m;i++){
			static node it;
			for(int j=1;j<=n;j++)it.ch[j]=f[j][i];
			for(int j=0;j<len[i-1];j++)
				for(int k=1;k<=n;k++){
					append(i,solve(max(split(it,k),vet[i-1][j])));
				}
		}
		for(int i=0,sum;sum=0,i<len[m];i++){
			for(int x=1;x<=n;x++)sum+=vet[m][i].ch[x];
			ans=std::max(ans,sum);
		}
		print(ans,'\n');
		for(int i=1;i<=m;i++)len[i]=0,vet[i].resize(0);
	}
}