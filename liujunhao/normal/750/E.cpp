#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
//
#define MAXN 200000
#define INF 0x3fffffff
char s[MAXN+10];
int n,m;
struct node{
	int f[5][5];
}tree[MAXN*4+10];
inline void update(int i){
	static int j,k,x;
	for(j=0;j<5;j++)
		for(k=0;k<5;k++){
			tree[i].f[j][k]=INF;
			for(x=j;x<=k;x++)
				tree[i].f[j][k]=min(tree[i].f[j][k],tree[i<<1].f[j][x]+tree[(i<<1)|1].f[x][k]);
		}
}
inline node merge(const node &x,const node &y){
	static node ret;
	int i,j,k;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++){
			ret.f[i][j]=INF;
			for(k=i;k<=j;k++)
				ret.f[i][j]=min(ret.f[i][j],x.f[i][k]+y.f[k][j]);
		}
	return ret;
}
inline void init(int i){
	static int j,k;
	for(j=0;j<5;j++)
		for(k=0;k<5;k++)
			tree[i].f[j][k]=INF;
}
int num[4]={2,0,1,7};
inline void build(int i,int l,int r){
	if(l==r){
		init(i);
		for(int j=0;j<5;j++){
			if(j<4&&s[l]-'0'==num[j])
				tree[i].f[j][j+1]=0,tree[i].f[j][j]=1;
			else if(j>=3&&s[l]=='6')
				tree[i].f[j][j]=1;
			else
				tree[i].f[j][j]=0;
		}
		return;
	}
	int mid((l+r)>>1);
	build(i<<1,l,mid);
	build((i<<1)|1,mid+1,r);
	update(i);
}
inline node get_ans(int i,int l,int r,int ll,int rr){
	if(ll<=l&&r<=rr)
		return tree[i];
	int mid((l+r)>>1);
	if(ll>mid)
		return get_ans((i<<1)|1,mid+1,r,ll,rr);
	if(rr<=mid)
		return get_ans(i<<1,l,mid,ll,rr);
	return merge(get_ans(i<<1,l,mid,ll,rr),get_ans((i<<1)|1,mid+1,r,ll,rr));
}
void read(){
	Read(n),Read(m);
	scanf("%s",s+1);
}
void solve(){
	build(1,1,n);
	int l,r;
	node t;
	while(m--){
		Read(l),Read(r);
		t=get_ans(1,1,n,l,r);
		printf("%d\n",t.f[0][4]==INF?-1:t.f[0][4]);
	}
}
int main()
{
	read();
	solve();
}