#include<bits/stdc++.h>
#define int long long
#define ll long long 
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
const int N=2e5+10;
int n,m,u,v,w;
ll s[N];
std::set<int> a,b;
std::vector<std::tuple<int,int,ll>> ans;
signed main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m);
	for(int i=1;i<=m;i++)read(u),read(v),read(w),s[u]+=w,s[v]-=w;
	for(int i=1;i<=n;i++){
		if(s[i]>0)a.insert(i);
		if(s[i]<0)b.insert(i);
	}
	while(a.size()&&b.size()){
		int u=*a.begin(),v=*b.begin();
		// printf("> %d %d | %d %d\n",u,v,s[u],s[v]);
		ll flow=std::min(s[u],-s[v]);
		ans.push_back(std::make_tuple(u,v,flow));
		s[u]-=flow,s[v]+=flow;
		if(!s[u])a.erase(u);
		if(!s[v])b.erase(v);
	}
	printf("%lu\n",ans.size());
	for(auto it:ans)print(std::get<0>(it),' '),print(std::get<1>(it),' '),print(std::get<2>(it),'\n');
}