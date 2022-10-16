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
int query1(int i,int n){
    vector<int>v(n,2);
    v[i]=1;
    cout<<"? ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout.flush();
    int a;cin>>a;
    return a;
}
int query2(int i,int n){
    vector<int>v(n,1);
    v[i]=2;
    cout<<"? ";
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<"\n";
    cout.flush();
    int a;cin>>a;
    return a;
}
void solve(){
    int n;cin>>n;
    vector<int>r(n+1);
    int loc1 = -1;
    int pred[n+1];
    int succ[n+1];
    for(int i=1;i<=n;i++){
        pred[i] = query1(i-1,n);
        succ[i] = query2(i-1,n);
        if(pred[i]==0){
            loc1 = i;
        }
    }
    int last = loc1;
    r[last]=1;
    for(int i=2;i<=n;i++){
        if(succ[last]!=last){
            last = succ[last];
        }else{
            for(int j=1;j<=n;j++){
                if(pred[j]==last && j!=last){
                    last = j;
                    break; 
                }
            }
        }
        r[last]=i;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<r[i]<<" ";
    cout<<"\n";
    cout.flush();
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