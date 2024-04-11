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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
void solve(){
    int n,k;cin>>n>>k;
    ll ogk = k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int>app(n,1);
    for(int i=0;i<n;i++){
        if(arr[i]<n) app[arr[i]]=0;
    }
    vector<int>toMakeMex(n+1,0);
    for(int i=1;i<=n;i++){
        toMakeMex[i] = toMakeMex[i-1] + app[i-1];
    }
    map<int,int>m;
    for(auto i:arr) m[i]++;
    vector<int>freq(n+1);
    for(auto i:m) freq[i.S]++;
    int curr = 1;
    int removed = 0;
    while(k>=curr && curr<=n){
        if(freq[curr]==0){
            curr++; 
            continue;
        }
        removed++;
        freq[curr]--;
        k-=curr;
    }
    ll ans = m.size() - removed;
    ll diff = m.size();
    for(int i=1;i<=n;i++){
        if(toMakeMex[i]>ogk) continue;
        if(freq[m[i-1]]==0){
            removed--;
            k+=m[i-1];
            while(k>=curr && curr<=n){
               if(freq[curr]==0){
                    curr++; 
                    continue;
                }
                removed++;
                freq[curr]--;
                k-=curr;
            }
        }else{
            freq[m[i-1]]--;
        }
        ans = min(ans,diff - removed - i);
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