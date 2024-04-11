#include <bits/stdc++.h>
using namespace std;




int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	vector<int> ans(0);
	for(int i=0;i<n;i++){
		if(i==n-1){
			ans.push_back(a[i]);
			continue;
		}
		if(a[i]>=a[i+1])ans.push_back(a[i]);
	}
	
	cout<<ans.size()<<endl;
	
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	return 0;
}