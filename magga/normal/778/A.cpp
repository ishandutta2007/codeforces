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
string s,t;
vector<int>p;
bool check(int mid){
    int n = s.size();
    vector<bool>flag(n);
    for(int i=0;i<mid;i++){
        flag[p[i]-1]=1;
    }
    int curr = 0;
    for(int i=0;i<s.size();i++){
        if(curr==t.size()) return true;
        if(!flag[i] && s[i]==t[curr]) curr++;
    }
    return curr == t.size();
}
void solve(){
    cin>>s>>t;
    int n = s.size();
    p.resize(n);
    for(int i=0;i<n;i++) cin>>p[i];
    int start = 0,end = n,mid,ans=0;
    while(start<=end){
        mid = (start + end + 1)>>1;
        if(check(mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
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