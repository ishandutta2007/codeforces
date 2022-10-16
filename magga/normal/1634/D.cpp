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
int query(int i,int j,int k){
    cout<<"? "<<i<<" "<<j<<" "<<k<<"\n";
    cout.flush();
    int t;cin>>t;
    return t;
}
void answer(int i,int j){
    cout<<"! "<<i<<" "<<j<<"\n";
    cout.flush();
}
void solve(){
    int n;cin>>n;
    int curr = 0;
    int ind = 2;
    for(int i=3;i<=n;i++){
        auto t = query(1,2,i);
        if(t > curr){
            curr = t;
            ind = i;
        }
    }
    map<pair<int,pii>,int>m;
    int curr2 = 0;
    int ind2 = 1;
    for(int i=2;i<=n;i++){
        if(i==ind) continue;
        auto t = query(1,ind,i);
        m[{1,{ind,i}}] = t;
        if(t > curr2){
            curr2 = t;
            ind2 = i;
        }
    }
    int val = 0;
    for(int i=2;i<=n;i++){
        if(i!=ind && i!=ind2){
            val = i;
            break;
        }
    }
    auto aiaj = query(ind,ind2,val);
    auto a1aj = query(1,ind2,val);
    auto a1ai = m[{1,{ind,val}}];
    if(aiaj >= max(a1aj,a1ai))
        answer(ind,ind2);
    else if(a1aj >= max(aiaj,a1ai))
        answer(1,ind2);
    else answer(1,ind);
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