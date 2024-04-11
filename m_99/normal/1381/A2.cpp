#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);
		
		string a,b;
		cin>>a>>b;
		int cnt = 0;
		vector<int> ans;
		vector<int> ind1,ind2;
		for(int i=0;i<n;i++){
			if(i%2==0){
				ind1.push_back(n-i/2);
			}
			else{
				ind1.push_back(2+i/2);
			}
			if(i%2==0){
				ind2.push_back(1+i/2);
			}
			else{
				ind2.push_back(n-i/2);
			}
		}
		
		for(int i=0;i<n;i++){
			char t = b[n-1-i];
			if(i%2==1){
				if(t=='1')t='0';
				else t='1';
			}
			if(a[ind2[i]-1]==t){
				ans.push_back(1);
				if(t=='1')a[ind2[i]-1] = '0';
				else a[ind2[i]-1] = '1';
			}
			ans.push_back(n-i);
		}
		cout<<ans.size();
		for(int i=0;i<ans.size();i++){
			cout<<' ';
			cout<<ans[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}