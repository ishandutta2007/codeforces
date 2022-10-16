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
    int n,m;cin>>n>>m;
    bool arr[n][m];
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            if(c=='.')
                arr[i][j]=0;
            else arr[i][j]=1;
        }   
    }
    int psum[m];
    for(auto &i:psum) i=0;
    for(int j=0;j<m-1;j++){
        for(int i=1;i<n;i++){
            if(arr[i][j] && arr[i-1][j+1]){
                psum[j+1]++;
            }
        }
    }
    for(int i=1;i<m;i++){
        psum[i]+=psum[i-1];
    }
    int q;cin>>q;
    int a,b;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(a==b) cout<<"YES"<<"\n";
        else if(psum[a-1]==psum[b-1]) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
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