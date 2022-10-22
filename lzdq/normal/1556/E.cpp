#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,q,a[MAXN],b[MAXN];
ll Calc(int l,int r){
	ll s1=0,s2=0;
	for(int i=l; i<=r; i++){
		if(a[i]>0){
			if(s1<a[i]) return -1;
			s2+=a[i];
			s1-=a[i];
		}
		if(a[i]<0){
			s1-=a[i];
			s2=max(0ll,s2+a[i]);
		}
	}
	if(!s1) return s2;
	return -1;
}
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
struct node{
	ll m,s;
}dat[MAXN<<2][2];
void Build(int k,int l,int r){
	ll &m1=dat[k][0].m,&m2=dat[k][1].m;
	ll &s1=dat[k][0].s,&s2=dat[k][1].s;
	for(int i=l; i<=r; i++){
		s1-=a[i];
		s2+=a[i];
		m1=max(m1,-s1);
		m2=max(m2,-s2);
	}
	if(l==r) return ;
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	return ;
}
ll s1,s2;
void Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		if(s1<dat[k][0].m){
			s1=-1;
			return;
		}
		s1+=dat[k][0].s;
		s2=max(s2,dat[k][1].m);
		s2+=dat[k][1].s;
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) Query(ls,x,y);
	if(mid<y) Query(rs,x,y);
	return ;
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<=n; i++)
		scanf("%d",b+i),a[i]-=b[i];
	Build(1,1,n);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		s1=s2=0;
		Query(1,1,n,l,r);
		if(s1) puts("-1");
		else printf("%lld\n",s2);
	}
	return 0;
}