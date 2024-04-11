#include<bits/stdc++.h>
using namespace std;
int n,q;
set<array<int,4> >s;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	s.insert({1,n,1,1});
	while(q--){
		int x,y;char c;cin>>x>>y>>c;
		if(s.empty()||(*s.begin())[0]>x){
			cout<<"0\n";
			continue;
		}
		auto t=*--s.lower_bound({x+1,0,0,0});
		if(t[0]>x||x>t[1]){
			cout<<"0\n";
		}else if(c=='U'){
			cout<<y-t[3]+1<<"\n";
			if(t[0]<x)
				s.insert({t[0],x-1,t[2],t[3]});
			if(x<t[1])
				s.insert({x+1,t[1],x+1,t[3]});
			s.erase(t);
		}else{
			cout<<x-t[2]+1<<"\n";
			if(t[0]<x)
				s.insert({t[0],x-1,t[2],y+1});
			if(x<t[1])
				s.insert({x+1,t[1],t[2],t[3]});
			s.erase(t);
		}
	}
}