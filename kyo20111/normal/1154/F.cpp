#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k,arr[202020],psum[2020],dp[2020];
vector<int> x,y;

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr+1,arr+1+n);
    for(int i=1;i<=k;i++) psum[i]=psum[i-1]+arr[i];
	for(int i=1;i<=k;i++) dp[i]=1e9;
	
    while(m--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(a > k) continue;
        x.push_back(a);
        y.push_back(b);
    }
    
    for(int i=0;i<=k;i++){
    	if(i) dp[i]=min(dp[i], dp[i-1]+arr[i]);
    	for(int j=0;j<x.size();j++){
    		if(x[j]+i > k) continue;
    		dp[x[j]+i] = min(dp[x[j]+i], dp[i]+psum[x[j]+i]-psum[y[j]+i]);
    	}
    }
    
    printf("%d",dp[k]);
}