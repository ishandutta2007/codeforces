#include<bits/stdc++.h>
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
const int N=2e5+10,mod=998244353;
struct z {
	int x;
	z(int x=0):x(x){}
	friend inline z operator*(z a,z b){return (long long)a.x*b.x%mod;}
	friend inline z operator-(z a,z b){return (a.x-=b.x)<0?a.x+mod:a.x;}
	friend inline z operator+(z a,z b){return (a.x+=b.x)>=mod?a.x-mod:a.x;}
}inv100,p[N];
inline z fpow(z a,int b){z s(1);for(;b;b>>=1,a=a*a)if(b&1)s=s*a;return s;}
struct pair{
	z x,y;
	inline z set(z k){return x*k+y;}
	friend inline pair operator*(const pair &x,const pair &y){return (pair){x.x*y.x,x.x*y.y+x.y};}
};
struct seg{
	struct node{
		int l,r,mid;
		pair x;
	}p[N<<2];
	void build(int u,int l,int r,pair foo(int)){
		p[u].l=l,p[u].r=r,p[u].mid=(l+r)>>1;
		if(l==r){p[u].x=foo(l);return;}
		build(u<<1,l,p[u].mid,foo);
		build(u<<1|1,p[u].mid+1,r,foo);
		p[u].x=p[u<<1].x*p[u<<1|1].x;
	}
	void modify(int u,int k,pair x){
		if(p[u].l==p[u].r){p[u].x=x;return;}
		modify(k<=p[u].mid?u<<1:u<<1|1,k,x);
		p[u].x=p[u<<1].x*p[u<<1|1].x;
	}
	pair query(int u,int l,int r){
		if(p[u].l==l&&p[u].r==r)return p[u].x;
		if(r<=p[u].mid)return query(u<<1,l,r);
		if(l>p[u].mid)return query(u<<1|1,l,r);
		return query(u<<1,l,p[u].mid)*query(u<<1|1,p[u].mid+1,r);
	}
}f,g,h,res;
int n,m;
std::set<int> set;
pair calc(int l,int r){
	z a=f.query(1,l,r).set(0);
	z b=g.query(1,l,r).set(1);
	z c=h.query(1,l,r).set(0);
	z inv=fpow(1-a,mod-2);
	// printf("calc %d %d >> %d %d %d >> %d %d\n",l,r,a.x,b.x,c.x,b*inv.x,c*inv.x);
	return (pair){b*inv,c*inv};
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m),p[0]=1,inv100=fpow(100,mod-2);
	for(int i=1;i<=n;i++)read((int&)p[i]),p[i]=p[i]*inv100;
	set.insert(0),set.insert(1),set.insert(n+1);
	f.build(1,0,n,[](int i){return (pair){p[i],1-p[i]};});
	g.build(1,0,n,[](int i){return (pair){p[i],z(0)};});
	h.build(1,0,n,[](int i){return (pair){p[i],z(1)};});
	res.build(1,0,n,[](int k){
		if(k==0)return calc(0,0);
		if(k==1)return calc(1,n);
		return (pair){1,0};
	});
	for(int x,i=1;i<=m;i++){
		read(x);
		// printf(">> %d\n",x);
		if(set.find(x)==set.end()){
			set.insert(x);
			auto it=set.find(x);
			int l=*std::prev(it),r=*std::next(it);
			res.modify(1,l,calc(l,x-1));
			res.modify(1,x,calc(x,r-1));
		}else{
			auto it=set.find(x);
			int l=*std::prev(it),r=*std::next(it);
			res.modify(1,l,calc(l,r-1));
			res.modify(1,x,{1,0});
			set.erase(it);
		}
		printf("%d\n",(res.query(1,0,n).set(0)-1).x);
		// for(int i=0;i<=n;i++)printf("[%d %d]%c",res.query(1,i,i).x.x,res.query(1,i,i).y.x," \n"[i==n]);
	}
	// printf(">> %d\n",(z(3)*fpow(4,mod-2)).x);
}