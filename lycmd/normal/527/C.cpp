#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q;
multiset<int>xcd,ycd,xl,yl;
signed main(){
	ios::sync_with_stdio(0);
	cin>>m>>n>>q;
	xcd.insert(0),xcd.insert(n),xl.insert(n);
	ycd.insert(0),ycd.insert(m),yl.insert(m);
	while(q--){
		char op;int p;cin>>op>>p;
		if(op=='H'){
			auto it=xcd.upper_bound(p);
			int r=*it,l=*(--it);
			xcd.insert(p);
			xl.erase(xl.lower_bound(r-l));
			if(p!=l)xl.insert(p-l);
			if(p!=r)xl.insert(r-p);
		}else{
			auto it=ycd.upper_bound(p);
			int r=*it,l=*(--it);
			ycd.insert(p);
			yl.erase(yl.lower_bound(r-l));
			if(p!=l)yl.insert(p-l);
			if(p!=r)yl.insert(r-p);
		}
		cout<<(*xl.rbegin())*(*yl.rbegin())<<"\n";
	}
}//