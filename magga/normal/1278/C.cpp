#include<bits/stdc++.h>
using namespace std;
void solve(){
	long long int n;cin>>n;
	long long int arr[2][n];
	long long int diff = 0;
	for(long long int i=n-1;i>=0;i--){
	    cin>>arr[0][i];
	    if(arr[0][i]==2){
	        arr[0][i]=-1;
	        diff--;
	    }else{
	        diff++;
	    }
	}
	for(long long int i=0;i<n;i++){
	    cin>>arr[1][i];
	    if(arr[1][i]==2){
	        arr[1][i]=-1;
	        diff--;
	    }else{
	        diff++;
	    }
	}
	long long int dp[n+1];
	dp[0]=0;
	for(long long int i=1;i<=n;i++){
	    dp[i]=dp[i-1]+arr[0][i-1];
	}
	map<long long int,long long int>m;
	m[0]=0;
	long long int val=0;
	for(long long int i=0;i<n;i++){
	    val+=arr[1][i];
	    if(m.find(val)==m.end()){
	        m[val]=i+1;
	    }
	}
    long long int ans=2*n;
    for(long long int i=0;i<=n;i++){
        if(m.find(diff-dp[i])!=m.end() && m[diff-dp[i]]+i<ans){
            ans=m[diff-dp[i]]+i;
        }
    }
    cout<<ans<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}