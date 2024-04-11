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
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    if(n<3){
        cout<<0<<"\n";
        return;
    }
    int ans = n-2;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pii d = {arr[j]-arr[i],j-i};
            int count = 0;
            for(int k=0;k<n;k++){
                pii val = {arr[i]*d.S + (k-i)*d.F,j-i};
                int p = __gcd(val.F,val.S);
                val.F/=p;
                val.S/=p;
                if(val.S!=1 || val.F!=arr[k]){
                    count++;
                }
            }
            ans = min(ans,count);
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