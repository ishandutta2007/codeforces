#include<bits/stdc++.h>
using namespace std;
long long int dp[100000]{0};
void pre(){
    for(long long int i=0;i<100000;i++){
        dp[i]=(i*(i+1))/2;
    }
}
void solve(){
	long long int a,b;cin>>a>>b;
	a=abs(a-b);
	long long int i =0;
	while(true){
	    if(dp[i]>=a && (dp[i]-a)%2==0){
	        break;
	    }
	    i++;
	}
	cout<<i<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1 ;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}