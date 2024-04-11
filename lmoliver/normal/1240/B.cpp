#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define D(N,E) for(int N=0;N<(int)(E);N++)
typedef vector<int> V;

template<class T=int>
T read(){
	T x=0;
	char ch=0;
	bool f=false;
	while(!isdigit(ch))f|=(ch=getchar())=='-';
	for(;isdigit(ch);ch=getchar())x=x*10+(ch^'0');
	return f?-x:x;
}

const int N=3.1e5;
int main(){
	int q=read();
	D(_,q){
		int n=read();
		map<int,V> mp;
		F(i,1,n){
			mp[read()].push_back(i);
		}
		map<int,pair<int,int>> qaq;
		for(auto p:mp){
			const auto &v=p.second;
			int mn=*min_element(v.begin(),v.end());
			int mx=*max_element(v.begin(),v.end());
			qaq[p.first]={mn,mx};
		}
		int ans=0;
		int cur=0;
		int r=0;
		for(auto p:qaq){
			if(r>=p.second.first){
				cur=0;
			}
			cur++;
			ans=max(ans,cur);
			r=p.second.second;
		}
		printf("%d\n",(int)mp.size()-ans);
	}
	return 0;
}