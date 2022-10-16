#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
// Please write the recurances once :(
void pre(){}
int v(char c){
    return int(c);
}
void solve(){
    ll n,m;cin>>n>>m;
    string s;cin>>s;
    string t;
    s = "0" + s +"0";
    int change = 10;
    int i = 0;
    while(i<m && change!=0){
        change = 0;
        t = s;
        for(int j=1;j<=n;j++){
            if(s[j]=='0' && v(s[j-1])+v(s[j+1])==v('1')+v('0')){
                t[j]='1';
                change++;
            }
        }
        s = t;
        i++;
    }
    for(int i=1;i<=n;i++){
        cout<<s[i];
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