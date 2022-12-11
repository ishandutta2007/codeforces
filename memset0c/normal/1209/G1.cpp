#include<bits/stdc++.h>
#define ll long long
// #define int long long
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
const int N=2e5+10;
int T,n,m,q,cur,max,lst,a[N],b[N];
ll ans;
std::set<int> set[N];
struct edge{
	int l,r,x;
	inline bool operator<(const edge &other)const{
		return l<other.l;
	}
}e[N];
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(q);
	for(int i=1;i<=n;i++)read(a[i]),b[++m]=a[i];
	std::sort(b+1,b+n+1),m=std::unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		a[i]=std::lower_bound(b+1,b+m+1,a[i])-b;
		set[a[i]].insert(i);
	}
	// for(int i=1;i<=n;i++)printf("%d%c",a[i]," \n"[i==n]);
	for(int i=1;i<=m;i++){
		e[i].l=*set[i].begin();
		e[i].r=*--set[i].end();
		e[i].x=set[i].size();
	}
	std::sort(e+1,e+m+1);
	// for(int i=1;i<=m;i++)printf("[%d %d %d]%c",e[i].l,e[i].r,e[i].x," \n"[i==m]);
	if(!q){
		lst=0,cur=0;
		for(int i=1;i<=m;i++){
			cur=std::max(cur,e[i].r);
			if(i==m||e[i+1].l>cur){
				// printf("> %d %d | %d %d\n",lst+1,i,i==m,e[i+1].l>e[i].r);
				max=0;
				for(int j=lst+1;j<=i;j++){
					max=std::max(max,e[j].x);
					ans+=e[j].x;
				}
				ans-=max;
				lst=i,cur=0;
			}
		}
		print(ans,'\n');
	}
}