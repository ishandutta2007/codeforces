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
    string s,t;cin>>s>>t;
    sort(s.begin(),s.end());
    vector<int>m(26);
    for(int i:s){
        m[i-'a']++;
    }
    bool t1 = 0;
    if(t=="abc") t1=1;
    if(m[0]==0 || m[1]==0 || m[2]==0){
        cout<<s<<"\n";
        return;
    }
    if(t1) swap(m[1],m[2]);
    for(int i=0;i<26;i++){
        if(i==1 && t1) for(int j=0;j<m[i];j++) cout<<'c';
        else if(i==2 && t1) for(int j=0;j<m[i];j++) cout<<'b';
        else for(int j=0;j<m[i];j++) cout<<char('a'+i);
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