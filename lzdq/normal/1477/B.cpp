#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,q,a[MAXN],b[MAXN],l[MAXN],r[MAXN];
char s[MAXN];
int ans;
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
int sum[MAXN<<2],tag[MAXN<<2];
inline void add(int k,int l,int r,int v){
	tag[k]=v;
	sum[k]=v*(r-l+1);
}
inline void pushup(int k){
	sum[k]=sum[lc]+sum[rc];
}
inline void pushdwn(int k,int l,int r){
	if(~tag[k]){
		int mid=l+r>>1;
		add(ls,tag[k]);
		add(rs,tag[k]);
		tag[k]=-1;
	}
}
void Build(int k,int l,int r){
	tag[k]=-1;
	if(l==r){
		sum[k]=b[l];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int k,int l,int r,int x,int y,int v){
	if(x<=l&&r<=y) return add(k,l,r,v);
	pushdwn(k,l,r);
	int mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y,v);
	if(mid<y) Modify(rs,x,y,v);
	pushup(k);
	return ;
}
int Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return sum[k];
	pushdwn(k,l,r);
	int mid=l+r>>1,res=0;
	if(x<=mid) res+=Query(ls,x,y);
	if(mid<y) res+=Query(rs,x,y);
	return res;
}
bool Check(int k,int l,int r){
	if(l==r) return sum[k]==a[l];
	int mid=l+r>>1;
	pushdwn(k,l,r);
	return Check(ls)&&Check(rs);
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		for(int i=1; i<=n; i++)
			a[i]=(s[i]=='1');
		scanf("%s",s+1);
		for(int i=1; i<=n; i++)
			b[i]=(s[i]=='1');
		Build(1,1,n);
		for(int i=1; i<=q; i++)
			scanf("%d%d",l+i,r+i);
		ans=1;
		for(int i=q; i; i--){
			int x=l[i],y=r[i];
			int len=y-x+1,cnt=Query(1,1,n,x,y);
			if(cnt<(len/2.0)){
				Modify(1,1,n,x,y,0);
			}else if(len-cnt<(len/2.0)){
				Modify(1,1,n,x,y,1);
			}else{
				ans=0;
				break;
			}
		}
		if(ans&&Check(1,1,n)) puts("YES");
		else puts("NO");
	}
	return 0;
}