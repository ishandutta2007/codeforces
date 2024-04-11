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
// WRITE DOWN THE RECCURANCES FFS 
// Please write the recurances once :(
void pre(){}
ll solver(int n,int k,vector<ll>arr){
    ll ans = 0;
    ll z = 0;
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        z = z + (arr[i]==0);
    }
    if(sum>z*k || sum<-z*k)
        return -1;
    ll curr = 0;
    ll tz = 0;
    for(int i=0;i<n;i++){
        curr += arr[i];
        tz += (arr[i] == 0);
        ll currSum = curr - min(tz*k,sum+(z-tz)*k);
        ll ref = currSum;
        ll bonus = currSum - curr;
        ans  = max(ans,abs(currSum)+1);
        ll pz = 0;
        for(int j=i+1;j<n;j++){
            pz +=  ( arr[j] == 0 );
            currSum += arr[j];
            ll ncurrSum = currSum + min(pz*k,(z - pz - tz)*k-sum-bonus);
            ans = max(ans,abs(ncurrSum-ref)+1);
        }
    }
    curr = 0;
    tz = 0;
    for(int i=0;i<n;i++){
        curr += arr[i];
        tz += (arr[i] == 0);
        ll currSum = curr + min(tz*k,(z-tz)*k - sum);
        ll ref = currSum;
        ll bonus = currSum - curr;
        ans  = max(ans,abs(currSum)+1);
        ll pz = 0;
        for(int j=i+1;j<n;j++){
            pz +=  (arr[j]==0);
            currSum += arr[j];
            ll ncurrSum = currSum - min(pz*k,(z - pz - tz)*k+sum+bonus);
            ans = max(ans,abs(ncurrSum-ref)+1);
        }
    }
    return ans;
}
void solve(){
    ll n,k;cin>>n>>k;
    vector<ll>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    ll ans = solver(n,k,arr);
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    solve();
}