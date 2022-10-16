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

#define MAXN   1000001 
int spf[MAXN];  
void sieve(){ 
    spf[1] = -1; 
    for (int i=2; i<MAXN; i++)  spf[i] = i; 
    for (int i=4; i<MAXN; i+=2) spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++){  
        if (spf[i] == i){  
            for (int j=i*i; j<MAXN; j+=i) 
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}  
vector<int> getFactorization(int x){ 
    vector<int> ret; 
    while (x != 1){ 
        ret.push_back(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

// Please write the recurances once :(
void pre(){
    sieve();
}
void solve(){
    int e,n;cin>>n>>e;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll f = 0;
        ll b = 0;
        if(spf[arr[i]]!=arr[i]) continue;
        int curr = i-e;
        while(curr>=0){
            if(arr[curr]==1){
                b++;
                curr-=e;
            }else{
                break;
            }
        }
        curr = i+e;
        while(curr<n){
            if(arr[curr]==1){
                f++;
                curr+=e;
            }else{
                break;
            }
        }
        ans += (f+1)*(b+1)-1;
        //cout<<i<<" "<<f<<" "<<b<<"\n";
    }
    cout<<ans<<"\n";
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