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
void pre(){}
void solve(){
    pii defga = {-1,-1};
    int n,d;cin>>n;
    vector<pii>arr(n+1);
    for(auto &i:arr) i = {-1,-1};
    for(int i=0;i<n;i++){
        cin>>d;
        if(arr[d]==defga){
            arr[d].F = i;
        }else{
            arr[d].S = i;
        }
    }
    vector<int>v(n);
    for(int i=0;i<=n;i++){
        if(arr[i].F!=-1 && arr[i].S!=-1){
            v[arr[i].F] = i;
            v[arr[i].S] = i;
        }
    }
    int ans = 0;
    int curr = -1;
    int next = -1;
    for(int i=0;i<n;i++){
        if(v[i]==0 && curr!=-1) ans++;
        else if(v[i]==0 && curr==-1) continue;
        else if(v[i]!=0){
            if(arr[v[i]].F==i){
                if(curr==-1) curr = v[i];
                else if(next==-1) next = v[i];
                else{
                    ans++;
                    if(arr[v[i]].S > arr[next].S) next = v[i];
                }
            }else{
                if(v[i]!=curr) ans++;
                if(v[i]==next) { 
                    next = -1;
                    ans++;
                }
                if(v[i]==curr){
                    curr = next;
                    next = -1;
                    if(curr!=-1) ans++;
                }
            }
        }
        //cout<<i<<" "<<curr<<" "<<next<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
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