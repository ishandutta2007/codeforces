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
    ll arr[n];
    int pos = -1;
    int count = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]==1){
            pos = i;
            count++;
        }
    }
    if(count!=1){
        cout<<"NO"<<"\n";
        return;
    }
    for(int i=1;i<n;i++){
        if(arr[(pos + i)%n]>arr[(pos + i - 1+n)%n]+1){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
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
/* 
    1 is where n aayeaga

*/