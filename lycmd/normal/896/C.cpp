#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,m,sd,vmx,t;
struct node{
	int l,r;mutable int v;
	node(int a=0,int b=0,int c=0):l(a),r(b),v(c){}
	int operator<(const node&rhs)const{
		return l<rhs.l;
	}
};
set<node>tr;
int rnd(){
	return t=sd,sd=(sd*7+13)%1000000007,t;
}
int gen(int k){
	return rnd()%k+1;
}
int qpow(int x,int y,int p){
	return y?qpow(x*x%p,y>>1,p)*(y&1?x:1)%p:1;
}
auto split(int x){
	if(x>n)return tr.end();
	auto it=--tr.upper_bound(node(x));
	if(it->l==x)return it;
	int l=it->l,r=it->r,v=it->v;
	tr.erase(it),tr.insert(node(l,x-1,v));
	return tr.insert(node(x,r,v)).first;
}
void add(int l,int r,int k){
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl;i!=itr;i++)
		i->v+=k;
}
void assign(int l,int r,int k){
	auto itr=split(r+1),itl=split(l);
	tr.erase(itl,itr),tr.insert(node(l,r,k));
}
int kth(int l,int r,int k){
	auto itr=split(r+1),itl=split(l);
	vector<pair<int,int> >t;
	for(auto i=itl;i!=itr;i++)
		t.push_back({i->v,i->r-i->l+1});
	sort(t.begin(),t.end());
	for(int i=0;i<t.size();i++)
		if(t[i].second<k)
			k-=t[i].second;
		else return t[i].first;
}
int sum(int l,int r,int k,int p){
	int res=0;
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl;i!=itr;i++)
		res=(res+qpow(i->v%p,k,p)*(i->r-i->l+1))%p;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>sd>>vmx;
	for(int i=1;i<=n;i++)
		tr.insert(node(i,i,gen(vmx)));
	while(m--){
		int op=gen(4),l=gen(n),r=gen(n);
		if(l>r)swap(l,r);
		int x=gen(op^3?vmx:r-l+1),y=op<4?0:gen(vmx);
		switch(op){
			case 1:add(l,r,x);break;
			case 2:assign(l,r,x);break;
			case 3:cout<<kth(l,r,x)<<"\n";break;
			case 4:cout<<sum(l,r,x,y)<<"\n";break;
		}
	}
}