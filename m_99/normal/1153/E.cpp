#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000

bool check(pair<int,int> P,vector<int> V){
	if(V[0]==V[2]){
		if(P.first==V[0])return true;
	}
	else{
		if(P.second==V[1])return true;
	}
	return false;
}

void show(vector<int> V){
	cout<<"? "<<V[0]<<' '<<V[1]<<' '<<V[2]<<' '<<V[3]<<endl;
}

pair<int,int> get_ans(vector<int> V){
	int ind;
	if(V[0]==V[2])ind = 3;
	else ind = 2;
	int ok = V[ind];
	int ng = 0;
	
	while(ok-ng>1){
		int mid = (ok+ng)/2;
		
		cout<<"? ";
		for(int j=0;j<4;j++){
			if(j!=0)cout<<' ';
			if(j==ind)cout<<mid;
			else cout<<V[j];
		}
		cout<<endl;
		
		int x;
		cin>>x;
		if(x%2==1)ok = mid;
		else ng = mid;
	}
	
	pair<int,int> ret;
	if(ind==3){
		ret.first = V[0];
		ret.second = ok;
	}
	else{
		ret.second = V[1];
		ret.first = ok;
	}
	
	return ret;
}

int main() {
	
	int n;
	cin>>n;
	
	vector<vector<int>> Q;
	
	for(int i=0;i<n;i++){
		Q.push_back({i+1,1,i+1,n});
		Q.push_back({1,i+1,n,i+1});
	}
	
	mt19937 engine(chrono::steady_clock::now().time_since_epoch().count());
	shuffle(Q.begin(),Q.end(),engine);
	
	vector<pair<int,int>> ans;
	
	for(int i=0;i<Q.size();i++){
		if(ans.size()!=0){
			if(check(ans[0],Q[i]))continue;
		}
		show(Q[i]);
		int x;
		cin>>x;
		
		if(x%2==1){
			ans.push_back(get_ans(Q[i]));
		}
		
		if(ans.size()==2)break;
	}
	
	cout<<"! "<<ans[0].first<<' '<<ans[0].second<<' '<<ans[1].first<<' '<<ans[1].second<<endl;
	
    return 0;
}