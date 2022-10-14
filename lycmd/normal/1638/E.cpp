#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010;
int n,q,v[N],a[N];
struct node{
	int l,r;mutable int v;
	node(int a=0,int b=0,int c=0):l(a),r(b),v(c){}
	int operator<(const node&rhs)const{
		return l<rhs.l;
	}
};
set<node>tr;
void add(int x,int y){
	for(;x<=n;x+=x&-x)v[x]+=y;
}
void add(int l,int r,int y){
	add(l,y),add(r+1,-y);
}
int ask(int x){
	return x?ask(x&(x-1))+v[x]:0; 
}
auto split(int x){
	if(x>n)return tr.end();
	auto it=--tr.upper_bound(node(x));
	if(it->l==x)return it;
	int l=it->l,r=it->r,v=it->v;
	tr.erase(it),tr.insert(node(l,x-1,v));
	return tr.insert(node(x,r,v)).first;
}
void assign(int l,int r,int k){
	auto itr=split(r+1),itl=split(l);
	for(auto i=itl;i!=itr;i++)
		add(i->l,i->r,a[i->v]);
	tr.erase(itl,itr),tr.insert(node(l,r,k));
	add(l,r,-a[k]);
}
int query(int x){
	auto it=tr.lower_bound(node(x));
	return(it==tr.end()||it->l>x?--it:it)->v;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>n>>q,tr.insert(node(1,n,1));q--;){
		string op;int x,y,k;
		switch(cin>>op,op[0]){
			case'A':cin>>x>>y,a[x]+=y;break;
			case'C':cin>>x>>y>>k,assign(x,y,k);break;
			case'Q':cin>>x,cout<<ask(x)+a[query(x)]<<"\n";
		}
	}
	return 0;
}