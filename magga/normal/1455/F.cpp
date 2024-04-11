#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<": ";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
int k;
char reduce(char c){
    if(c=='a') return c;
    if(c-'a'==k-1)
        return 'a';
    else
        return c-1;
}
void solve(){
    int n;cin>>n>>k;
    string s;cin>>s;
    string dp[2][n];
    dp[0][0]=reduce(s[0]);
    dp[1][0]=s[0];
    for(int i=1;i<n;i++){
        dp[1][i] = dp[0][i-1] + s[i];
        string temp = dp[0][i-1] + s[i];
        swap(temp[i],temp[i-1]);
        dp[0][i] = min(temp,dp[0][i-1]+reduce(s[i]));
        temp = dp[1][i-1] + s[i];
        swap(temp[i],temp[i-1]);
        char a = temp[i-1];
        temp[i-1] = reduce(a);
        dp[0][i] = min(dp[0][i],temp);
        temp[i-1] = a;
        if(i!=1){
            swap(temp[i-1],temp[i-2]);
            dp[0][i] = min(dp[0][i],temp);
        }
        //cout<<dp[0][i]<<" "<<dp[1][i]<<"\n";
    }
    cout<<dp[0][n-1]<<"\n";
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