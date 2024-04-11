#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define INF 1000000000
#define pii pair<long long int,long long int>
#define F first
#define S second
typedef long long ll;
using namespace std;

long long int mod = 1e9+7;
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
void solve(){
    ll n,q,d;cin>>n>>q>>mod;
    ll fib[n+1];
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++)
        fib[i]=add(fib[i-1],fib[i-2]);
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    for(int i=0;i<n;i++){
        cin>>d;
        arr[i] = sub(arr[i],d);
    }
    ll compressedArray[n];
    compressedArray[0]=arr[0];
    compressedArray[1]=sub(arr[1],arr[0]);
    set<int>nonZero;
    for(int i=2;i<n;i++){
        compressedArray[i]=sub(arr[i],add(arr[i-1],arr[i-2]));
    }
    for(int i=0;i<n;i++){
        if(compressedArray[i]!=0){
            nonZero.insert(i);
        }
        arr[i]=compressedArray[i];
    }
    char c;
    int l,r;
    for(int i=0;i<q;i++){
        cin>>c>>l>>r;
        l--;
        if(c=='A'){
            arr[l] = add(arr[l],1);
            if(arr[l]==0) nonZero.erase(l);
            else nonZero.insert(l);
            if(r<n){
                arr[r]   = sub(arr[r]  ,fib[r-l+1]);
                if(arr[r]==0) nonZero.erase(r);
                else nonZero.insert(r);
            }
            if(r<n-1){
                arr[r+1] = sub(arr[r+1],fib[r-l]);
                if(arr[r+1]==0) nonZero.erase(r+1);
                else nonZero.insert(r+1);
            }
        }else{
            arr[l] = sub(arr[l],1);
            if(arr[l]==0) nonZero.erase(l);
            else nonZero.insert(l);
            if(r<n){
                arr[r]   = add(arr[r]  ,fib[r-l+1]);
                if(arr[r]==0) nonZero.erase(r);
                else nonZero.insert(r);
            }
            if(r<n-1){
                arr[r+1] = add(arr[r+1],fib[r-l]);
                if(arr[r+1]==0) nonZero.erase(r+1);
                else nonZero.insert(r+1);
            }
        }
        if(nonZero.size()==0){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
    }
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