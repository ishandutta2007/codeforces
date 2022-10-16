#include<bits/stdc++.h>
using namespace std;
void pre(){}
int dp[401][401][401]{0};
void solve(){
    string s,t;cin>>s>>t;
    int n = s.size(),m=t.size();
    int dp[401][401]{0};
    int dp2[401][401]{0};
    string val[n];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    set<int>s1;
    for(int p=0;p<n;p++){
        s1.clear();
        for(int j=0;j<m;j++){
            if(s[p]==t[j]){
                s1.insert(j);
            }
        }
        for(int i=0;i<401;i++)for(int j=0;j<401;j++)dp2[i][j]=dp[i][j];
        for(int i=0;i<401;i++){
            for(int j=0;j<401;j++){
                if(s1.find(dp[i][j])!=s1.end()){
                    dp[i][j]++;
                }
            }
        }
        auto p1 = s1.rbegin();
        while( p1!=s1.rend() ){
            auto j = *p1;
            for(int i = 400;i >= 0;i--){
                dp2[i][j+1]=max(dp2[i][j+1],dp2[i][j]);
            }
            p1++;
        }
        for(int i=0;i<401;i++)for(int j=0;j<401;j++)dp[i][j]=max(dp[i][j],dp2[i][j]);
    }
    for(int i=0;i<m;i++){
        if(dp[i][i]==m){
            cout<<"YES"<<"\n";
            return;
        }
    }
    cout<<"NO"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}