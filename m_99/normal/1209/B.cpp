#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	string S;
	cin>>S;
	
	vector<int> a(n),b(n);
	
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	
	int maxi = 0;
	
	for(int i=0;i<=1000;i++){
		for(int j=0;j<n;j++){
			if(i-b[j]>=0&&(i-b[j])%a[j]==0){
				S[j] ^= 1;
			}
		}
		int cnt = 0;
		for(int j=0;j<n;j++){
			if(S[j]=='1')cnt++;
		}
		
		maxi = max(maxi,cnt);
	}
	
	cout<<maxi<<endl;
	
	
	return 0;
}