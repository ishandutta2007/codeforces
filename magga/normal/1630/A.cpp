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
    int n,k;cin>>n>>k;
    vector<bool>a(n);
    if( n==4 && k==3 ){
        cout<<-1<<"\n";
        return;
    }
    vector<pii>ans;
    if(k!=n-1){
        a[k]=1;
        a[n-1-k]=1;
        a[n-1]=1;
        a[0]=1;
        ans.push_back({k,n-1});
        if(k!=0)
            ans.push_back({0,n-1-k});
    }else{
        a[n-1]=1;
        a[n-2]=1;
        a[n-3]=1;
        a[n-4]=1;
        a[0]=1;
        a[1]=1;
        a[2]=1;
        a[3]=1;
        ans.push_back({n-2,n-1});
        ans.push_back({0,1});
        ans.push_back({2,n-4});
        ans.push_back({3,n-3});
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            ans.push_back({i,n-1-i});
            a[i]=1;
            a[n-1-i]=1;
        }
    }
    int check = 0;
    set<int>s;
    for(auto i:ans){
        check += i.F & i.S;
        s.insert(i.F);
        s.insert(i.S);
    }
    if(check==k || s.size()==n){
        for(auto i:ans){
            cout<<i.F<<" "<<i.S<<"\n";
        }
    }
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