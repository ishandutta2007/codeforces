#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001
vector<long long> pow10(1,1);
vector<long long> pow11(1,1);


int main(){
	
	
	rep(i,15){
		pow10.push_back(pow10.back()*10);
		pow11.push_back(pow11.back()*11);
	}
	
	

	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long s,n;
		cin>>s>>n;
		//cout<<s<<','<<n<<endl;
		int m = pow10.size();
		vector<long long> ans;
		vector<long long> t;

		while(s!=0){
			t.push_back(s%10);
			s/=10;
		}
		
		rep(i,t.size()){
			rep(j,t[i]){
				ans.push_back(pow10[i]);
			}
		}
		/*
		rep(i,t.size()){
			cout<<t[i]<<',';
		}
		cout<<endl;
		*/
		while(ans.size()<n){
			int ind = -1;
			rep(i,ans.size()){
				if(ans[i]==1)continue;
				if(ind==-1)ind = i;
				if(ans[i]<ans[ind])ind = i;
			}
		//	cout<<ind<<endl;
			int v = ans[ind];

			ans.erase(ans.begin()+ind);
			rep(i,10){
				ans.push_back(v/10);
			}
			/*
			rep(i,ans.size()){
				cout<<ans[i]<<',';
			}
			cout<<endl;
			*/
		}
		
		
		while(ans.size()>n){
			ans[0] += ans.back();
			ans.pop_back();
		}
		
			
		
		rep(i,n){
			if(i!=0)cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}