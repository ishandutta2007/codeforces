#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}

const int N=1e5+10;
int T,n,a[N],b[N],l[N],r[N],anc[N];

inline int find(int x){
	return anc[x]==x?x:anc[x]=find(anc[x]);
}

int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		read(n);
		std::multiset<int> set;
		anc[n+1]=n+1;
		for(int i=1;i<=n;i++){
			read(a[i]);
			b[a[i]]=i;
			anc[i]=i;
			l[i]=r[i]=i;
			set.insert(1);
		}
		bool fl=true;
		for(int i=1;i<=n;i++){
			int u=b[i];
			// printf("u = %d\n",u);
			if(r[u]-l[u]+1!=*set.rbegin()){
				fl=false;
				break;
			}
			set.erase(set.find(r[u]-l[u]+1));
			int v=find(r[u]+1);
			// printf("v = %d (%d)\n",v,r[u]+1);
			anc[find(u)]=v;
			if(v<=n){
				set.erase(set.find(r[v]-l[v]+1));
				l[v]=l[u];
				set.insert(r[v]-l[v]+1);
			}
			// puts("!");
			// for(int i=1;i<=n;i++)printf("%d%c",l[i]," \n"[i==n]);
			// for(int i=1;i<=n;i++)printf("%d%c",r[i]," \n"[i==n]);
			// for(int i=1;i<=n;i++)printf("%d%c",find(i)," \n"[i==n]);
		}
		puts(fl?"Yes":"No");
	}
}