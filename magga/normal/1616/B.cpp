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
    string s;cin>>s;
    string ans;
    ans+=s[0];
    if(s.size()==1 || s[0]==s[1]){
        cout<<s[0]<<s[0]<<"\n";
        return;
    }
    for(int i=1;i<n;i++){
        if(s[i]>s[i-1])
            break;
        ans+=s[i];
    }
    s = ans;
    reverse(s.begin(),s.end());
    cout<<ans+s<<"\n";
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