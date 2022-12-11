#include<bits/stdc++.h>
#define mp std::make_pair
// #define log(...) (void(0))
#define log(...) fprintf(stderr,__VA_ARGS__)
#define debug log("\33[2mPassing [%s] out LINE %d\33[0m\n",__FUNCTION__,__LINE__);
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool mrk=0;
	while(!isdigit(c))mrk^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(mrk)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}

const int N=1e5+10;
int n,max,fa[N],cnt[N],cur[N];
std::vector<int> G[N];
std::vector<std::pair<int,int>> opt;

inline void mov(int first,int second){
	opt.push_back(std::make_pair(first,second));
}

void dfs(int u,int fa,int out){
	// printf("dfs %d %d %d\n",u,fa,out);
	mov(u,out);
	int cnt=0,in=out,deg=u==1?G[u].size():((int)G[u].size()-1);
	if(out==max&&u>1){
		out=in-(deg-cnt)-1,mov(u,out);
	}
	for(int v:G[u])if(v!=fa){
		cnt++;
		dfs(v,u,++out);
		mov(u,out);
		if(out==max&&u>1){
			out=in-(deg-cnt)-1,mov(u,out);
		}
	}
	if(u!=1&&out!=in-1)out=in-1,mov(u,out);
}

int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int u,v,i=1;i<n;i++){
		read(u),read(v);
		G[u].push_back(v),G[v].push_back(u);
	}
	for(int u=1;u<=n;u++){
		max=std::max((int)G[u].size(),max);
	}
	// ++max;
	dfs(1,0,0);
	printf("%lu\n",opt.size());
	for(auto x:opt)printf("%d %d\n",x.first,x.second);
}