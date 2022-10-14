#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,q,ans1,ans2;
map<pair<int,int>,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	while(q--){
		char op,c;int x,y;
		cin>>op;
		switch(op){
			case'+':{
				cin>>x>>y>>c;
				mp[{x,y}]=c;
				if(mp.find({y,x})!=mp.end())
					ans1++,ans2+=mp[{y,x}]==c;
				break;
			}
			case'-':{
				cin>>x>>y;
				if(mp.find({y,x})!=mp.end())
					ans1--,ans2-=mp[{y,x}]==mp[{x,y}];
				mp.erase({x,y});
				break;
			}
			case'?':
				cin>>x,cout<<(x%2&&ans1||x%2==0&&ans2?"YES\n":"NO\n");
		}
	}
}