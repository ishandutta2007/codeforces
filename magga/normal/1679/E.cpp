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

long long fact[1000001];
long long ifact[1000001];
long long inverses[1000001];
void setFactorial(){
    fact[0]=1;
    ifact[0]=1;
    inverses[1]=1;
    for(int i=1;i<=1000000;i++){
        fact[i] = mul(fact[i-1],i);
        if(i>1) inverses[i] = mod - (mod/i) * inverses[mod%i] % mod;
        ifact[i] = mul(ifact[i-1],inverses[i]);
    }
}

// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
void pre(){}
ll subsetSum[1<<17][18]{0};
void solve(){
    int n;cin>>n;
    ll req = 0;
    string s;cin>>s;
    for(auto i:s) req+=(i=='?');
    for(int center=0;center<n;center++){
        int mask = 0;
        int count = 0;
        int leftEnd = center;
        int rightEnd = center;
        pii currAns = {0,0};
        while(leftEnd>=0 && rightEnd<n){
            if(s[leftEnd]==s[rightEnd]){
                if(s[leftEnd]=='?'){
                    currAns.F++;
                    count++;
                    if(leftEnd!=rightEnd) count++;
                }
            }else if(s[leftEnd]=='?'){
                mask|=(1<<(s[rightEnd]-'a'));
                count++;
            }else if(s[rightEnd]=='?'){
                mask|=(1<<(s[leftEnd]-'a'));
                count++;
            }else{
                break;
            }
            for(int p=1;p<=17;p++){
                 subsetSum[mask][p]+=power(p,currAns.F+req-count);
            }
            leftEnd--;
            rightEnd++;
        }
    }
    for(int center=0;center<n;center++){
        int mask = 0;
        int count = 0;
        int leftEnd = center-1;
        int rightEnd = center;
        pii currAns = {0,0};
        while(leftEnd>=0 && rightEnd<n){
            if(s[leftEnd]==s[rightEnd]){
                if(s[leftEnd]=='?'){
                    currAns.F++;
                    count+=2;
                }
            }else if(s[leftEnd]=='?'){
                mask|=(1<<(s[rightEnd]-'a'));
                count++;
            }else if(s[rightEnd]=='?'){
                mask|=(1<<(s[leftEnd]-'a'));
                count++;
            }else{
                break;
            }
            for(int p=1;p<=17;p++){
                subsetSum[mask][p]+=power(p,currAns.F+req-count);
            }
            leftEnd--;
            rightEnd++;
        }
    }
    //memory optimized, super easy to code.
    for(int i = 0;i < 17; ++i) for(int mask = 0; mask < (1<<17); ++mask){
	    if(mask & (1<<i)){
		    for(int j=1;j<=17;j++){
                subsetSum[mask][j] = add(subsetSum[mask][j],subsetSum[mask^(1<<i)][j]);
            }
        }
    }
    int q;cin>>q;
    for(int i=0;i<q;i++){
        string query;cin>>query;
        int mask = 0;
        for(auto i:query){
            mask|=(1<<(i-'a'));
        }
        cout<<subsetSum[mask][query.size()]<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}