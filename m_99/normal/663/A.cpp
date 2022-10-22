#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000


int main(){
	string ope;
	while(true){
		char c;
		cin>>c;
		if(c=='?')continue;
		if(c=='=')break;
		ope += c;
	}
	
	int n;
	cin>>n;
	
	vector<int> ans(ope.size()+1,n);
	int sum = n*ans.size();
	for(int i=0;i<ope.size();i++){
		if(ope[i]=='-'){
			ans[i+1] = 1;
			sum -= n+1;
		}
	}

	if(sum<n){
		cout<<"Impossible"<<endl;
		return 0;
	}
	
	for(int i=0;i<ans.size();i++){
		//cout<<sum<<endl;
		if(i==0||ope[i-1]=='+'){
			int k = min(n-1,sum-n);
			ans[i] -= k;
			sum -= k;
		}
		else{
			int k = min(n-1,sum-n);
			ans[i] += k;
			sum -= k;
		}
	}

	if(sum==n){
		cout<<"Possible"<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i];
			cout<<' ';
			if(i+1!=ans.size()){
				cout<<ope[i]<<' ';
			}
		}
		cout<<"= "<<n<<endl;
	}
	else{
		cout<<"Impossible"<<endl;
	}
	
	return 0;
}