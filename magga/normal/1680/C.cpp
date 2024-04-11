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
struct prefixSums{
    vector<pii>arr;
    prefixSums(string s){
        arr.resize(s.size()+1);
        for(int i=1;i<=s.size();i++){
            arr[i]=arr[i-1];
            if(s[i-1]=='1'){
                arr[i].F++;
            }else{
                arr[i].S++;
            }
        }
    }
    pii query(int i,int j){
        return {arr[j+1].F-arr[i].F,arr[j+1].S-arr[i].S};
    }
};
void solve(){
    string s;cin>>s;
    int count[2]{0};
    for(auto i:s) count[i-'0']++;
    ll ans = count[1];
    int curr = 0;
    prefixSums a(s);
    for(int i=0;i<s.size();i++){
        int start = i,end = s.size()-1,mid;
        while(start<=end){
            mid = (start + end + 1)/2;
            auto cru = a.query(i,mid);
            cru.F = count[1]-cru.F;
            ans = min(ans,max(cru.F,cru.S));
            if(cru.F<cru.S){
                end = mid-1;
            }else if(cru.S<cru.F){
                start = mid + 1;
            }else{
                break;
            }
        }
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