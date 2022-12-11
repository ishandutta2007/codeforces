#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=4010;
int n,m,siz[N],c[N],res[N],vis[N];
std::vector<int> son[N];
void dfs1(int u){
	siz[u]=1;
	for(int v:son[u])dfs1(v),siz[u]+=siz[v];
}
void dfs2(int u){
	for(int c=0,lst=::c[u];;){
		++c;
		if(!vis[c]){
			if(lst)--lst;
			else{
				res[u]=c;
				vis[c]=1;
				break;
			}
		}
	}
	for(int v:son[u])dfs2(v);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int p,i=1;i<=n;i++){
		read(p),read(c[i]);
		son[p].push_back(i);
	}
	dfs1(son[0][0]);
	// for(int i=1;i<=n;i++)print(siz[i]," \n"[i==n]);
	for(int i=1;i<=n;i++)if(c[i]>=siz[i]){
		puts("NO");
		return 0;
	}
	dfs2(son[0][0]);
	puts("YES");
	for(int i=1;i<=n;i++)print(res[i]," \n"[i==n]);
}