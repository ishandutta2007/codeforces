#include<cstdio>
const int N=100002;
int n,i,j,k,a,b,c,h[N],t[N],v[N];
double s[N],f[N];
void dfs1(int i){
	s[i]=1;
	for(int j=h[i];j;j=t[j]){
		dfs1(v[j]);
		s[i]+=s[v[j]];
	}
}
void dfs2(int i){
	for(int j=h[i];j;j=t[j]){
		f[v[j]]=f[i]+(s[i]-s[v[j]]-1)/2+1;
		dfs2(v[j]);
	}
}
int main(){
	scanf("%d",&n);
	for(b=2;b<=n;b++){
		scanf("%d",&a);
		t[++k]=h[a];h[a]=k;v[k]=b;
	}
	dfs1(1);
	f[1]=1;
	dfs2(1);
	for(i=1;i<=n;i++)
		printf("%.7lf ",f[i]);
}