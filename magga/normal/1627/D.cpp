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
// Please write the recurances once :(
vector<int>factors[1000001];
int val = 1000000;
void pre(){
    for(int i=1;i<=val;i++){
        for(int j=2;i*j<=val;j++){
            factors[i*j].push_back(i);
        }
    }
}
int cou = 0;
int f[1000001]{0};
void add(int k){
    if(f[k]==k) return;
    f[k]=k;
    cou++;
    for(auto j:factors[k]){
        if(f[j]==0){
            f[j]=k;
        }else if(__gcd(k,f[j])==j){
            add(j);
        }else{
            f[j] = __gcd(k,f[j]);
        }
    }
}
void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    for(auto i:arr) add(i);
    cout<<cou - n<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}