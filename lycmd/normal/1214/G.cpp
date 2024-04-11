#include<bits/stdc++.h>
using namespace std;
int const N=2010;
int n,m,t,c[N];
bitset<N>b[N];
queue<int>q;
struct cmp{
	int operator()(int x,int y)const{
		return c[x]<c[y]||(c[x]==c[y]&&x<y); 
	}
};
set<int,cmp>p;
void print(int ax,int bx){
	if(ax>bx)swap(ax,bx); 
	auto t=b[ax]^b[bx];
	int ay=(t&b[ax])._Find_first(),by=(t&b[bx])._Find_first();
	if(ay>by)swap(ay,by);
	cout<<ax<<" "<<ay<<" "<<bx<<" "<<by<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		p.insert(i);
	for(int a,l,r;t--;){
		cin>>a>>l>>r;
		if(p.count(a))
			p.erase(a),q.push(a);
		c[a]=(b[a]^=(~(bitset<N>())<<(r+1))^(~(bitset<N>())<<l)).count();
		for(;!q.empty();q.pop()){
			int x=q.front();
			auto il=p.lower_bound(x),ir=p.upper_bound(x);
			if(il!=p.begin()){
				int l=*--il;
				if((b[l]|b[x])!=b[x]){
					print(l,x);break;
				}
			}
			if(ir!=p.end()){
				int r=*ir;
				if((b[r]|b[x])!=b[r]){
					print(x,r);break;
				}
			}
			p.insert(x);
		}
		if(q.empty())
			cout<<"-1\n";
	}
}