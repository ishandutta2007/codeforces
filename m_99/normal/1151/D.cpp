#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	vector<pair<int,pair<int,int>>> V(n);
	
	for(int i=0;i<n;i++){
		cin>>V[i].second.first>>V[i].second.second;
		V[i].first = V[i].second.first-V[i].second.second;
	}
	sort(V.begin(),V.end(),greater<pair<int,pair<int,int>>>());
	
	long long ans = 0;
	
	for(int i=0;i<n;i++){
		int j = i+1;
		ans += (long long)V[i].second.first*(j-1)+(long long)V[i].second.second*(n-j);
	}
	
	cout<<ans<<endl;
	
	return 0;
}