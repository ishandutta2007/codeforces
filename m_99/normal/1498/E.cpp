#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){
	
	int n;
	cin>>n;
	
	vector<int> k(n);
	rep(i,n){
		cin>>k[i];
	}
	
	vector<pair<int,pair<int,int>>> V;
	rep(i,n){
		for(int j=i+1;j<n;j++){
			V.emplace_back(abs(k[i]-k[j]),make_pair(i,j));
		}
	}
	
	sort(V.rbegin(),V.rend());
	
	rep(i,V.size()){
		
		int x = V[i].second.first,y = V[i].second.second;
		if(k[x]<k[y])swap(x,y);
		cout<<"? "<<x+1<<' '<<y+1<<endl;
		string ans;
		cin>>ans;
		if(ans=="Yes"){
			cout<<"! "<<x+1<<' '<<y+1<<endl;
			return 0;
		}
		
	}
	
	cout<<"! "<<0<<' '<<0<<endl;
			return 0;
		
	
    return 0;
}