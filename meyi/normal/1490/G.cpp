#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
inline int qr(){
	int in=0;char ch;bool f=false;
	while(!isdigit(ch=getchar()))f|=(ch=='-');
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return f?-in:in;
}
template<class T>
void qw(T out){
	if(out<0)putchar('-'),out=-out;
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct node{
	ll val;
	int id;
	inline bool operator<(const node &k)const{
		return val<k.val;
	}
}sum[maxn];
int a,ans,n,m,t[19][maxn],t_case,x;
ll rd;
void build(){
	for(ri i=1;i<=n;++i)t[0][i]=sum[i].id;
	ri k=log2(n)+1;
	for(ri i=1;i<=k;++i)
		for(ri j=1;j+(1<<i)<=n+1;++j)
			t[i][j]=min(t[i-1][j],t[i-1][j+(1<<(i-1))]);
}
int query(int l,int r){
	ri k=log2(r-l+1);
	return min(t[k][l],t[k][r-(1<<k)+1]);
}
inline int half(ll k){
	int ret=0,l=1,r=n;
	while(l<=r){
		int mid=l+r>>1;
		if(k<=sum[mid].val)ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
int main(){
	t_case=qr();
	while(t_case--){
		n=qr(),m=qr();
		for(ri i=1;i<=n;++i)sum[i].val=sum[i-1].val+qr(),sum[i].id=i;
		rd=sum[n].val;
		sort(sum+1,sum+n+1);
		build();
		while(m--){
			x=qr();
			ans=0;
			if(x>sum[n].val){
				if(rd<=0){
					qw(-1),putchar(32);
					continue;
				}
				ans=ceil(1.0*(x-sum[n].val)/rd);
				x-=ans*rd;
			}
			qw(1ll*ans*n+query(half(x),n)-1),putchar(32);
		}
		putchar(10);
	}
	return 0;
}