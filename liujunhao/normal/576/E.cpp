#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAXN 500000
#define MAXM 500000
#define MAXQ 500000
#define MAXK 50
#define pos first
#define color second
using namespace std;
typedef pair<int,char>pic;
queue<pic>change[MAXM+10];
vector<pic>v[MAXM<<2];
pic q[MAXQ+10];
int n,m,k,Q,tp;
short c[MAXM+10];
struct node{
	int u,v;
}edge[MAXM+10];
template<class T>
void Read(T &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			return;
		}
}
struct Union_fs;
pair<Union_fs*,int>s[MAXM<<2];
struct Union_fs{
	int fa[MAXN+10];
	char dep[MAXN+10],rk[MAXN+10];
	int find(int x){
		while(fa[x])
			x=fa[x];
		return x;
	}
	int Get_dis(int x){
		int ret=0;
		while(fa[x])
			ret^=dep[x],x=fa[x];
		return ret;
	}
	void Union(int x,int y){
		int z=Get_dis(x)^Get_dis(y)^1;
		x=find(x),y=find(y);
		if(x==y)
			return;
		if(rk[x]>rk[y])
			swap(x,y);
		if(rk[x]==rk[y])
			rk[y]++,s[++tp]=make_pair(this,-y);
		fa[x]=y,dep[x]=z;
		s[++tp]=make_pair(this,x);
	}
}dsu[MAXK+1];
void restore(int bt){
	while(tp>bt){
		if(s[tp].second<0)
			s[tp].first->rk[-s[tp].second]--;
		else{
			s[tp].first->fa[s[tp].second]=0;
			s[tp].first->dep[s[tp].second]=0;
		}
		tp--;
	}
}
void read(){
	Read(n),Read(m),Read(k),Read(Q);
	int i;
	for(i=1;i<=m;i++)
		Read(edge[i].u),Read(edge[i].v);
	for(i=1;i<=Q;i++){
		Read(q[i].pos),Read(q[i].color);
		change[q[i].pos].push(pic(i,q[i].color));
	}
	for(i=1;i<=m;i++)
		change[i].push(pic(Q,0));
}
void insert(int i,int l,int r,int ll,int rr,const pic &val){
	int mid=(l+r)>>1;
	if(l==ll&&r==rr){
		v[i].push_back(val);
		return;
	}
	if(rr<=mid)
		insert(i<<1,l,mid,ll,rr,val);
	else if(ll>mid)
		insert((i<<1)|1,mid+1,r,ll,rr,val);
	else
		insert(i<<1,l,mid,ll,mid,val),insert((i<<1)|1,mid+1,r,mid+1,rr,val);
}
void partition(int p,int l,int r){
	int mid=(l+r)>>1,bt=tp,x,y,size=v[p].size();
	for(int i=0;i<size;i++){
		x=edge[v[p][i].pos].u,y=edge[v[p][i].pos].v;
		dsu[v[p][i].color].Union(x,y);
	}
	v[p].clear();
	if(l==r){
		Union_fs &dsu=::dsu[q[l].color];
		x=edge[q[l].pos].u;
		y=edge[q[l].pos].v;
		if(dsu.find(x)!=dsu.find(y)||dsu.Get_dis(x)^dsu.Get_dis(y))
			puts("YES"),c[q[l].pos]=q[l].color;
		else
			puts("NO");
		change[q[l].pos].pop();
		if(l!=Q)
			insert(1,1,Q,mid+1,change[q[l].pos].front().pos,pic(q[l].pos,c[q[l].pos]));
	}
	else{
		partition(p<<1,l,mid);
		partition((p<<1)|1,mid+1,r);
	}
	restore(bt);
}
int main()
{
	read();
	partition(1,1,Q);
}