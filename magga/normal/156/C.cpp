#include<bits/stdc++.h>
using namespace std;
const long long int mod = 1e9+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int a,long long int b){return (a*b)%mod;}
long long int dib(long long int a,long long int b){return (a*inv(b))%mod;}
int val(char c){
    return int(c)-'a';
}
long long dp[101][2501]{0};
void pre(){
    dp[0][0]=1;
    for(int i=1;i<=100;i++){
        for(int j = 0;j<=25*i;j++){
            for(int k=0;k<26;k++){
                if(j-k>=0)
                dp[i][j]+=dp[i-1][j-k];
                dp[i][j]%=mod;
            }
        }
    }
}
void solve(){
    string s;cin>>s;
    int n = s.size();
    int oo = 0;
    for(auto i:s)oo+=val(i);
    cout<<(dp[n][oo]-1+mod)%mod<<"\n";
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