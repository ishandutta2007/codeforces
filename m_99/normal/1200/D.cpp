#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 100000000

int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<string> S(n);
	
	for(int i=0;i<n;i++)cin>>S[i];
		
	vector<int> black_l(n,Inf),black_r(n,-Inf),black_t(n,Inf),black_b(n,-Inf);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(S[i][j]=='B'){
				black_l[i] = min(black_l[i],j);
				black_r[i] = max(black_r[i],j);
				black_t[j] = min(black_t[j],i);
				black_b[j] = max(black_b[j],i);
			}
		}
	}
	
	vector<vector<int>> if1(n,vector<int> (n-k+1,0));//if1[i][j] yi x()j
	
	for(int i=0;i<n;i++){
		if(black_l[i]==Inf)continue;
		for(int j=0;j<n-k+1;j++){
			if(j<=black_l[i]&&j+k-1>=black_r[i]){
				if1[i][j]=1;
			}
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<n-k+1;j++){
			if1[i][j] += if1[i-1][j];
		}
	}
	
	
	vector<vector<int>> if2(n,vector<int> (n-k+1,0));//if2[i][j] xi y()j
	
	for(int i=0;i<n;i++){
		if(black_t[i]==Inf)continue;
		for(int j=0;j<n-k+1;j++){
			if(j<=black_t[i]&&j+k-1>=black_b[i]){
				if2[i][j] = 1;
			}
		}
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<n-k+1;j++){
			if2[i][j] += if2[i-1][j];
		}
	}
	int ans = 0;
	for(int i=0;i<n-k+1;i++){
		for(int j=0;j<n-k+1;j++){
			int a = 0;
			a += if1[i+k-1][j];
			if(i!=0)a -= if1[i-1][j];
			a += if2[j+k-1][i];
			if(j!=0)a -= if2[j-1][i];
			ans = max(ans,a);
		}
	}
	for(int i=0;i<n;i++){
		if(black_l[i]==Inf)ans++;
		if(black_t[i]==Inf)ans++;
	}
	
	cout<<ans<<endl;
	
		
	
	return 0;
}