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
void solve(){
    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<int>>prefixSums(m,vector<int>(n+1));
    int start = -1*m;
    int end = -1;
    int sum = 0;
    while(end<(n*m-1)){
        end++;
        if(end<s.size())
            sum += (s[end] - '0');
        if(start>=0){
            sum -= (s[start] - '0');
        }
        start++;
        if(sum>0){
            prefixSums[end%m][end/m]++;
            prefixSums[end%m][n]--;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            prefixSums[j][i] +=  prefixSums[j][i-1];
        }
    }
    int curr = 0;
    int p = 0;
    vector<int>cols(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[p]=='1'){
                if(cols[p%m]==0){
                    cols[p%m]=1;
                    curr++;
                }
            }
            cout<<curr+prefixSums[j][i]<<" ";
            p++;
        }
    }
    cout<<"\n";
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