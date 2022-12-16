#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200200;
struct P{
	int x,y;
	P(){}
	P(int _x,int _y):x(_x),y(_y){}
	bool operator<(const P o)const{
		return y!=o.y?y>o.y:x<o.x;
	}
};
int n;
P p[N];
map<int,int> sx,sy;
struct BIT{
	int a[N];
	void add(int x,int v){
		// cerr<<"+ "<<x<<" "<<v<<endl;
		for(;x<=n;x+=x&-x){
			a[x]+=v;
		}
	}
	int query(int x){
		// cerr<<"? "<<x<<endl;
		int ans=0;
		for(;x>0;x-=x&-x){
			ans+=a[x];
		}
		// cerr<<"> "<<ans<<endl;
		return ans;
	}
	int query(int l,int r){
		return query(r)-query(l-1);
	}
}bit;
bool has[N]={false};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		sx[p[i].x]=0;
		sy[p[i].y]=0;
	}
	for(auto &i:sx){
		static int cx=0;
		i.second=++cx;
	}
	for(auto &i:sy){
		static int cy=0;
		i.second=++cy;
	}
	for(int i=1;i<=n;i++){
		p[i].x=sx[p[i].x];
		p[i].y=sy[p[i].y];
		// cerr<<p[i].x<<","<<p[i].y<<endl;
	}
	sort(p+1,p+n+1);
	LL ans=0;
	for(int i=1;i<=n;i++){
		int x=p[i].x;
		int r=i+1<=n&&p[i+1].y==p[i].y?p[i+1].x-1:n;
		// cerr<<"x="<<x<<" r="<<r<<endl;
		LL d=(LL)(x-1<1?1:bit.query(1,x-1)+1)*(LL)(x+1>r?1:bit.query(x+1,r)+1);
		// cerr<<x<<","<<p[i].y<<" -> "<<d<<endl;
		ans+=d;
		if(!has[x]){
			bit.add(x,1);
			has[x]=true;
		}
	}
	printf("%lld\n",ans);
	return 0;
}