#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,d;cin>>n;
    set<long long int>s;
    long long int count=0;
    vector<long long int>v;
    map<long long int,long long int>m;
    for(long long int i=0;i<n;i++){
        cin>>d;
        if(m.find(d)!=m.end()){
            m[d]+=d;
        }else{
            m[d]=d;
            count++;
        }
        s.insert(d);
    }
    long long int dp[count]{0};
    long long int dp1[count]{0};
    long long int i=0;
    for(pair<long long int,long long int>p:m)
    {
        if(i==0){
            dp[0] = p.second;
            dp1[0] = p.first;
        }else if(i==1){
            if(dp1[0]+1==p.first && dp[0]<p.second){
                dp1[1]=p.first;
                dp[1]=p.second;
            }else if(dp1[0]+1==p.first && dp[0]>=p.second){
                dp1[1]=dp1[0];
                dp[1]=dp[0];
            }else{
                dp1[1]=p.first;
                dp[1]=p.second+dp[0];
            }
        }else{
            if(dp1[i-1]+1==p.first && dp[i-1]<p.second+dp[i-2]){
                dp1[i]=p.first;
                dp[i]=p.second+dp[i-2];
            }else if(dp1[i-1]+1==p.first && dp[i-1]>=p.second+dp[i-2]){
                dp1[i]=dp1[i-1];
                dp[i]=dp[i-1];
            }else{
                dp1[i]=p.first;
                dp[i]=p.second+dp[i-1];
            }
        }
        //cout<<dp[i]<<endl;
        i++;
    }
    if(count==1){
        cout<<dp[count-1]<<endl;  
    }else if(dp[count-1]>dp[count-2]){
        cout<<dp[count-1]<<endl;
    }else{
        cout<<dp[count-2]<<endl;
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	solve(); 
}