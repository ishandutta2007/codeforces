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

const long long int mod = 998244353;
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
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}

// Please write the recurances once :(
void pre(){}
pair<string,long long> dnc(string s){
    if(s.size()==1) return {s,1};
    int n = s.size();
    string left = s.substr(1,(n-1)/2);
    string right = s.substr((n+1)/2);
    auto left_ans = dnc(left);
    auto right_ans = dnc(right);
    if(left_ans.F == right_ans.F){
        return {s[0] + left_ans.F + right_ans.F , mul(left_ans.S,right_ans.S)};
    }else if(left_ans.F < right_ans.F){
        return {s[0] + left_ans.F + right_ans.F , mul(2,mul(left_ans.S,right_ans.S))};
    }else{
        return {s[0] + right_ans.F + left_ans.F , mul(2,mul(left_ans.S,right_ans.S))};
    }
}
string preorder;
void genertate_preorder(long long i,long long n,string &s){
    preorder += s[i-1];
    if(2*i<=n){
        genertate_preorder(2*i,n,s);
        genertate_preorder(2*i+1,n,s);
    } 
}
void solve(){
    ll n;cin>>n;
    n = (1ll<<n) - 1;
    string s;cin>>s;
    genertate_preorder(1,n,s);
    cout<<dnc(preorder).S<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}