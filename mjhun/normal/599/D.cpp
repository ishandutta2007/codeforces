#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull x;
stack<pair<ull,ull> > q;
vector<pair<ull,ull> > sol;

int main(){
	cin>>x;x*=6;
	for(ull n=1;;++n){
		ull k=2*n*n*n;
		if(k>x)break;
		k+=3*n*n;
		if(k>x)break;
		k+=n;
		if(k>x)break;
		ull w=3*n*(n+1);
		if((x-k)%w==0){
			ull m=(x-k)/w+n;
			sol.push_back(make_pair(n,m));
			q.push(make_pair(m,n));
		}
	}
	while(!q.empty()){
		if(q.top().first!=q.top().second)
			sol.push_back(make_pair(q.top().first,q.top().second));
		q.pop();
	}
	cout<<sol.size()<<endl;
	for(int i=0;i<sol.size();++i){
		cout<<sol[i].first<<' '<<sol[i].second<<endl;
	}
	return 0;
}