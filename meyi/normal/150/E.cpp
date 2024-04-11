#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int md,v,v_,to;
	inline edge(int a=0,int b=0,int c=0,int d=0):md(a),v(b),v_(c),to(d){}
	inline bool operator<(const edge &k)const{
		return md<k.md;
	}
};
vector<edge>e[maxn];
bool vis[maxn];
int dep[maxn],md[maxn],mx[maxn],rt,siz[maxn],tot;
void calc_siz(int p,int f){
	mx[p]=0;
	siz[p]=1;
	for(auto i:e[p])
		if(!vis[i.to]&&i.to!=f){
			calc_siz(i.to,p);
			ckmax(md[p],md[i.to]);
			ckmax(mx[p],siz[i.to]);
			siz[p]+=siz[i.to];
		}
	ckmax(mx[p],tot-siz[p]);
	if(mx[p]<mx[rt])rt=p;
}
void calc_md(int p,int f){
	md[p]=dep[p]=dep[f]+1;
	for(auto i:e[p])
		if(!vis[i.to]&&i.to!=f){
			calc_md(i.to,p);
			ckmax(md[p],md[i.to]);
		}
}
int cnt,prt[maxn],psiz[maxn];
void init(int p){
	++cnt;
	prt[cnt]=p,psiz[cnt]=tot;
	vis[p]=true;
//	for(auto &i:e[p])
//		if(!vis[i.to]){
//			calc_md(i.to,0);
//			i.md=md[i.to];
//		}
//	sort(e[p].begin(),e[p].end());
	for(auto i:e[p])
		if(!vis[i.to]){
			rt=0,tot=siz[i.to];
			calc_siz(i.to,0);
			init(rt);
		}
}
template<typename T>
struct dq{
	int hd,tl;
	T v[maxn];
	inline dq(){hd=1;}
	inline T front(int ex=0){return v[hd+ex];}
	inline T back(int ex=0){return v[tl-ex];}
	inline void pop_front(){++hd;}
	inline void pop_back(){--tl;}
	inline void push(T k){v[++tl]=k;}
	inline int size(){return tl-hd+1;}
	inline void clear(){hd=1,tl=0;}
};
dq<int>q1;
int ans1,ans2,dis[maxn],ep[maxn],fa[maxn],L,n,R,val[maxn];
inline void insert(int k){
	while(q1.size()&&val[q1.back()]<=val[k])q1.pop_back();
	q1.push(k);
}
bool bfs(int s,int len1,int len2,int f,int ml){
	dep[s]=len1,dis[s]=len2,fa[s]=f;
	q1.clear();
	queue<int>q2;
	q2.push(s);
	vector<int>tmp;
	while(q2.size()){
		ri p=q2.front();q2.pop();
		if(dep[p]>R)break;
		tmp.push_back(p);
		ri nl=max(L-dep[p],0),nr=R-dep[p];
		while(ml>=nl){
			if(val[ml]>-n)insert(ml);
			--ml;
		}
		while(q1.size()&&q1.front()>nr)q1.pop_front();
		if(q1.size()&&dis[p]+val[q1.front()]>=0){
			ans1=p,ans2=ep[q1.front()];
			return true;
		}
		for(auto j:e[p])
			if(!vis[j.to]&&j.to!=fa[p]){
				dep[j.to]=dep[p]+1;
				dis[j.to]=dis[p]+j.v;
				fa[j.to]=p;
				q2.push(j.to);
			}
	}
	for(auto p:tmp)
		if(dis[p]>val[dep[p]]){
			ep[dep[p]]=p;
			val[dep[p]]=dis[p];
		}
	return false;
}
inline bool check(int k){
	for(ri i=1;i<=n;++i){
		for(auto &j:e[i])j.v=(j.v_>=k?1:-1);
		vis[i]=false;
	}
	for(ri i=1;i<=n;++i)
		if(psiz[i]>1){
			rt=prt[i];
			vis[rt]=true;
			memset(val,-0x3f,sizeof(int)*(psiz[i]+1));
			dep[rt]=dis[rt]=fa[rt]=val[0]=0;
			ep[0]=rt;
			for(auto j:e[rt])
				if(!vis[j.to]&&bfs(j.to,1,j.v,rt,min(psiz[i],R)))
					return true;
		}
	return false;
}
int main(){
	scanf("%d%d%d",&n,&L,&R);
	for(ri i=1,x,y,z;i<n;++i){
		scanf("%d%d%d",&x,&y,&z);
		e[x].emplace_back(0,0,z,y),e[y].emplace_back(0,0,z,x);
	}
	mx[0]=INT_MAX,tot=n;
	calc_siz(1,0);
	init(rt);
	ri l=0,r=1e9;
	while(l<=r){
		ri mid=l+r>>1;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	printf("%d %d",ans1,ans2);
	return 0;
}