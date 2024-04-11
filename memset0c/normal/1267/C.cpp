#include<bits/stdc++.h>
#define fuck() puts("-1"),exit(0)
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
const int N=2e3+10;
int n,lst,d[N],fa[N];
std::vector<int> vet[N];
std::vector<std::pair<int,int>> ans;
inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void add(int u,int v){
	// printf("add %d %d\n",u,v);
	ans.push_back(std::make_pair(u,v));
}
inline void insert(int x){
	if(!d[x])return;
	vet[d[x]].push_back(x),++lst;
}
inline int querymin(){
	for(int i=1;i<=n;i++)if(vet[i].size()){
		int u=*vet[i].rbegin(); vet[i].pop_back(),--lst;
		return u;
	}
	return -1;
}
inline int querymax(int fl=false){
	for(int i=n;i;i--)if((!fl||((i&1)&&i>1))&&vet[i].size()){
		int u=*vet[i].rbegin(); vet[i].pop_back(),--lst;
		return u;
	}
	return -1;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;i++)read(d[i]),insert(i);
	while(lst){
		int u=querymin();
		// printf("> %d\n",u);
		if(!lst)fuck();
		if(d[u]==1){
			int x=querymax(1); if(x==-1)x=querymax();
			add(u,x),d[x]-=1,insert(x);
		}else if(d[u]==2){
			if(!vet[2].size())fuck();
			if(lst==vet[2].size()){
				if(vet[2].size()<2)fuck();
				add(u,vet[2][0]),add(u,vet[2][vet[2].size()-1]);
				for(int i=1;i<vet[2].size();i++)add(vet[2][i-1],vet[2][i]);
				break;
			}
			if(lst==1)fuck();
			int v=querymin(),x=querymax();
			add(x,u),add(x,v),add(u,v),d[x]-=2,insert(x);
		}else fuck();
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	for(auto it:ans)fa[find(it.first)]=find(it.second);
	for(int i=1;i<=n;i++)if(find(i)!=find(1))fuck();
	printf("%lu\n",ans.size());
	for(auto it:ans)printf("2 %d %d\n",it.first,it.second);
	int a605;
} // 1