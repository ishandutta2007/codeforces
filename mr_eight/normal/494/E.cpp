#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define UF(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
using namespace std;
#define mid ((v[pos].l+v[pos].r)>>1)
int n,m,k,a,b,c,d;
struct node{
    int l,r;
    int mmin,tag;
    int v;
}v[5000002];
int lc[5000002],rc[5000002],cnt=1;
inline node operator+(const node &x,const node &y){
    return {x.l,y.r,min(x.mmin,y.mmin),0,x.mmin<y.mmin?x.v^(y.l-1)^y.r:(x.mmin>y.mmin?y.v^(x.l-1)^x.r:x.v^y.v)};
}
inline void pushdown(int pos){
	if(!lc[pos])v[lc[pos]=++cnt]={v[pos].l,mid,0,0,0};
	if(!rc[pos])v[rc[pos]=++cnt]={mid+1,v[pos].r,0,0,0};
	if(v[pos].tag){
		v[lc[pos]].tag+=v[pos].tag;
		v[lc[pos]].mmin+=v[pos].tag;
		v[rc[pos]].tag+=v[pos].tag;
		v[rc[pos]].mmin+=v[pos].tag;
		v[pos].tag=0;
	}
}
inline void pushup(int pos){
	v[pos]=v[lc[pos]]+v[rc[pos]];
}
inline void add(int pos,int ql,int qr,int w){
	if(ql<=v[pos].l&&qr>=v[pos].r){
		v[pos].tag+=w;
		v[pos].mmin+=w;
	}else{
		pushdown(pos);
		if(ql<=mid)add(lc[pos],ql,qr,w);
		if(qr>mid)add(rc[pos],ql,qr,w);
		pushup(pos);
	}
}
inline int query(){
	return v[1].v;
}
struct S{
	int p,l,r,v;
};
vector<S>upd;
inline int calc(int x,int y){
	x^=x>>1,y^=y>>1;
	int ans=0;
	F(i,0,30){
		if((x>>i&1)&&__builtin_parity(y>>i))ans^=1<<i;
		if((y>>i&1)&&__builtin_parity(x>>(i+1)))ans^=1<<i;
	}
	return ans;
}
inline bool cmp(const S &x,const S &y){
	return x.p<y.p;
}
int main(){
	v[1]={0,1000000000,0,0,0};   
 	cin>>n>>m>>k;
	F(i,1,m){
		scanf("%d%d%d%d",&a,&c,&b,&d);
		upd.push_back({a,c,d,1});
		upd.push_back({b+1,c,d,-1});
	}
	sort(upd.begin(),upd.end(),cmp);
	int ans=0;
	F(i,0,upd.size()-2){
		add(1,upd[i].l,upd[i].r,upd[i].v);
		ans^=calc(query(),(upd[i+1].p-1)^(upd[i].p-1));//cerr<<upd[i].p<<" "<<ans<<endl;
	}
	k=31-__builtin_clz(k);
	F(i,k+1,30)if(ans>>i&1)ans^=(1<<i)^(1<<k);
	puts(ans?"Hamed":"Malek");
    return 0;
}