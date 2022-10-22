#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],cnt,ed[maxn*30],k,n,trie[maxn*30][2];
vector<int>ans;
map<int,vector<int>>p;
inline void insert(int x,int y){
	ri now=0;
	for(ri i=29;~i;--i){
		ri nxt=(x>>i)&1;
		if(!trie[now][nxt])trie[now][nxt]=++cnt;
		now=trie[now][nxt],ed[now]=y;
	}
}
inline int query(int x){
	ri now=0;
	for(ri i=29;~i;--i){
		ri nxt=(x>>i)&1;
		if((k>>i)&1)now=trie[now][nxt^1];
		else{
			if(trie[now][nxt^1])return ed[trie[now][nxt^1]];
			now=trie[now][nxt];
		}
		if(!now)return -1;
	}
	return ed[now];
}
int main(){
	scanf("%d%d",&n,&k);
	if(!k){
		printf("%d\n",n);
		for(ri i=1;i<=n;++i)printf("%d ",i);
		return 0;
	}
	ri l=__lg(k)+1;
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		p[a[i]>>l].push_back(i);
	}
	for(auto ele:p){
		vector<int>id=ele.second;
		for(ri i:id)insert(a[i],i);
		for(ri i:id){
			ri j=query(a[i]);
			if(~j){
				ans.push_back(i),ans.push_back(j);
				goto skip;
			}
		}
		ans.push_back(id.front());
		skip:;
		for(ri i=0;i<=cnt;++i)ed[i]=trie[i][0]=trie[i][1]=0;
		cnt=0;
	}
	if(ans.size()>1){
		printf("%d\n",(int)ans.size());
		for(ri i:ans)printf("%d ",i);
	}
	else printf("-1");
	return 0;
}