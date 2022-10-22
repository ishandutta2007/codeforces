#include <bits/stdc++.h>
using namespace std;
#define modulo m
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> ans(n);
	int ind = n;
	for(int i=0;i<n;i++){
		if(m==0){
			ind = i;
			break;
		}
		
		ans[i] = i+1;
		
		int k = i/2;
		
		if(k<=m){
			m -= k;
		}
		else{
			k = k-m;
			ans[i] = ans[2*k] + ans[i-1];
			m = 0;
		}
	}
	
	for(int i = ind;i<n;i++){
		if(i==ind){
			ans[i] = 100000000;
		}
		else{
			ans[i] = ans[i-1] + 10005;
		}
	}

	if(m!=0){
		cout<<-1<<endl;
		return 0;
	}

	for(int i=0;i<n;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	
	
	
	return 0;
}