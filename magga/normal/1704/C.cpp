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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// WRITE DOWN THE RECCURANCES FFS 
void pre(){}
void solve(){
    long long int n,m;cin>>n>>m;
    vector<long long int>s(m);
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    long long int answer = 0;
    vector<long long int>ranges;
    for(int i=0;i<m-1;i++){
        ranges.push_back(s[i+1]-s[i]-1);
    } 
    ranges.push_back(n - (s[m-1] - s[0] + 1));
    sort(ranges.begin(),ranges.end());
    reverse(ranges.begin(),ranges.end());
    long long int curr = 0;
    for(int i=0;i<ranges.size();i++){
        ranges[i]-=curr;
        if(ranges[i]<=0) continue;
        if(ranges[i]<=2){
            curr+=2;
            answer++;
        }else{
            curr+=4;
            answer+=ranges[i] - 1;
        }
    }
    cout<<n - answer<<"\n";
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