#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define chtholly ios::sync_with_stdio(0);
#define tree cin.tie(0);
typedef long long ll;
struct cho_tree{
	int l,r;
	mutable ll value;
	inline cho_tree(int l_,int r_=-1,ll v=0){
		l=l_,r=r_,value=v;
	}
	inline bool operator<(cho_tree k)const{return l<k.l;}
};
set<cho_tree> c;
#define cho_it set<cho_tree>::iterator
inline cho_it cho_split(int pos){	// 
	register cho_it i=c.lower_bound(cho_tree(pos));
	if(i!=c.end()&&i->l==pos)return i;
	--i;
	register int l=i->l,r=i->r;
	register ll v=i->value;
	return c.erase(i),c.insert(cho_tree(l,pos-1,v)),c.insert(cho_tree(pos,r,v)).first;
}
inline void cho_assign(int l,int r,ll v){	// 
	c.erase(cho_split(l),cho_split(r+1));
	c.insert(cho_tree(l,r,v));
}
inline void cho_add(int l,int r,ll v){	// 
	register cho_it il=cho_split(l),ir=cho_split(r+1);
	while(il!=ir){
		il->value+=v;
		++il;
	}
}
inline ll cho_get(int l,int r,int s){
	vector<pair<ll,int> >p;
	p.clear();
	register cho_it il=cho_split(l),ir=cho_split(r+1);
	while(il!=ir){
		p.push_back(make_pair(il->value,il->r-il->l+1));
		++il;
	}
	sort(p.begin(),p.end());
	for(auto i:p){
		s-=i.second;
		if(s<1)return i.first;
	}
}
inline ll qpow(ll num,ll power, ll mod){
	num%=mod;
	register ll res=1;
	while(power)res=(power&1?res*num%mod:res),num=num*num%mod,power>>=1;
	return res;
}
inline ll pow_sum(int l,int r,ll power,ll mod){
	register cho_it il=cho_split(l),ir=cho_split(r+1);
	register ll sum=0;
	while(il!=ir){
		sum=(sum+ll(il->r-il->l+1)*qpow(il->value,power,mod))%mod;
		++il;
	}
	return sum;
}
namespace io{
	template<class T>
	inline void qr(T &in){
		in=0;bool f=false;char ch;
		do ch=getchar(),f|=(ch=='-');while(ch<48||ch>57);
		while(ch>47&&ch<58)in=(in<<1)+(in<<3)+(ch^48),ch=getchar();
		if(f)in=-in;
	}
	template<class T>
	void qw(T out){
		if(out<0)putchar('-'),out=-out;
		if(out>9)qw(out/10);
		putchar(out%10|48);
	}
}
using namespace io;
namespace random{
	ll seed,vmax;
	inline ll rnd(){
		register ll ret=seed;
		seed=(seed*7+13)%1000000007;
		return ret;
	}
}
using namespace random;
int main(int argc,char *argv[]){
	chtholly tree
	int n,m;
	qr(n),qr(m),qr(seed),qr(vmax);
	for(register int i=1;i<=n;++i)c.insert(cho_tree(i,i,(rnd()%vmax)+1));
	while(m--){
		register int op=(rnd()%4)+1,l=(rnd()%n)+1,r=(rnd()%n)+1;
		if(l>r)swap(l,r);
		int x=(op==3?(rnd()%(r-l+1))+1:(rnd()%vmax)+1),y=(op==4?(rnd()%vmax)+1:NULL);
		switch(op){
			case 1:{
				cho_add(l,r,x);
				break;
			}
			case 2:{
				cho_assign(l,r,x);
				break;
			}
			case 3:{
				qw(cho_get(l,r,x)),putchar(10);
				break;
			}
			case 4:{
				qw(pow_sum(l,r,x,y)),putchar(10);
				break;
			}
		}
	}
}