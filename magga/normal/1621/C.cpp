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
int query(int i){
    cout<<"? "<<i<<"\n";
    cout.flush();
    int r;cin>>r;
    return r;
}
void answ(vector<int>a){
    cout<<"! ";
    for(int i=1;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
    cout.flush();
}
void solve(){
    int n,q;cin>>n;
    vector<int>ans(n+1);
    vector<int>curr;
    for(int i=1;i<=n;i++){
        if(ans[i]!=0) continue;
        curr.push_back(query(i));
        while(true){
            int a = query(i);
            if(a==curr[0]) break;
            curr.push_back(a);
        }
        int t = curr.size();
        for(int j=0;j<t;j++){
            ans[curr[j]] = curr[(j + 1)%t];
        }
        curr.clear();
    }
    answ(ans);
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