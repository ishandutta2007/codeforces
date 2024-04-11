#include <bits/stdc++.h>
using namespace std;
#define modulo 988244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000





int main(){
	
	int m;
	cin>>m;
	
	vector<int> A(m);
	vector<pair<int,int>> B(m);
	for(int i=0;i<m;i++)cin>>A[i];
	
	for(int i=0;i<m;i++){
		cin>>B[i].first;
		B[i].second=i;
	}
	
	sort(A.begin(),A.end(),greater<int>());
	sort(B.begin(),B.end());
	
	vector<int> ans(m);
	
	for(int i=0;i<m;i++){
		ans[B[i].second]=A[i];
	}
	
	for(int i=0;i<m;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
		
	
	
    return 0;
}