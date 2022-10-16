#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
using namespace std;
const long long int mod = 1e15+7;
long long int power(long long int x,long long int y){  
    long long int res = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0){   
        if (y & 1)  
            res = (res*x) % mod;  
        y = y>>1;
        x = (x*x) % mod; 
    }  
    return res;
}  
long long int h1[1000000],h2[1000000];
long long int inv(long long int a){return power(a,mod-2);}
long long int add(long long int a,long long int b){return (a+b)%mod;}
long long int sub(long long int a,long long int b){return (a-b+mod)%mod;}
long long int mul(long long int &a,long long int &b){return (a*b)%mod;}
long long int divi(long long int a,long long int b){return (a*inv(b))%mod;}
long long int p1 = 31,p2=7,p3=91;
pair<long long int,long long int> has(set<int>&s){
    pair<long long int,long long int>p={0,0};
    int curr = 0;
    for(auto &i:s){
        p.first+=i*h1[curr];
        p.second+=i*h2[curr];
        curr++;
    }
    return p;
}
void pre(){
    h1[0]=p1;
    h2[0]=p2;
    for(int i=1;i<1000000;i++){
        h1[i]=mul(h1[i-1],p1);
        h2[i]=mul(h2[i-1],p2);
    }
}
void solve(){
    long long int n,m,u,v;cin>>n>>m;
    set<int>arr[n+1];
    for(int i=0;i<m;i++){
        cin>>u>>v;
        arr[u].insert(v);
        arr[v].insert(u);
    }
    map<pair<int,int>,long long int>m1;
    for(int i=0;i<n;i++){
        m1[has(arr[i+1])]++;
    }
    long long int ans = 0;
    for(auto &i:m1){
        ans+=(i.second*(i.second-1))/2;
    }
    for(int i=0;i<n;i++){
        arr[i+1].insert(i+1);
    }
    m1.clear();
    for(int i=0;i<n;i++){
        m1[has(arr[i+1])]++;
    }
    for(auto &i:m1){
        ans+=(i.second*(i.second-1))/2;
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