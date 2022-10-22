#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 2000000000000000000

bool dfs(vector<int> a,int last){
	for(int i=0;i<a.size();i++){
		if(i==last)continue;
		if(a[i]==0)continue;
		a[i]--;
		if(!dfs(a,i))return true;
		a[i]++;
	}
	return false;
}

int main(){
	/*
	for(int i=0;i<5;i++){
		for(int j=i;j<5;j++){
			for(int k=j;k<5;k++){
				for(int l=k;l<6;l++){
					vector<int> a = {i,j,k,l};
					cout<<i<<','<<j<<','<<k<<','<<l<<','<<dfs(a,-1)<<endl;
				}
			}
		}
	}
*/

	int _t;
	cin>>_t;
	
	for(int _=0;_<_t;_++){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		int maxi = 0;
		int sum = 0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum += a[i];
			maxi = max(maxi,a[i]);
		}
		
		if(n==2){
			if(a[0]!=a[1])cout<<"T"<<endl;
			else cout<<"HL"<<endl;
			continue;
		}
		
		if(maxi*2<=sum&&n!=1&&sum%2==0)cout<<"HL"<<endl;
		else cout<<"T"<<endl;
		
		
	}
	
	return 0;
}