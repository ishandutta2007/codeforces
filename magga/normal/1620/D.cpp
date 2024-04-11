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
    int n,d;cin>>n;
    int ma = 0;
    bool a[3]{0};
    bool present = false;
    set<int>s;
    for(int i=0;i<n;i++){
        cin>>d;
        s.insert(d);
        if(d==1) present = true;
        a[d%3]=1;
        ma = max(ma,d);
    }
    if((!a[1]) && (!a[2])){
        cout<<ma/3<<"\n"; //optimal 
    }else if(a[1]^a[2]){
        cout<<ma/3 + 1<<"\n"; // optimal 
    }else if((a[1]&a[2]) && ma%3==0){
        cout<<ma/3 + 1<<"\n"; // optimal 
    }else if((a[1]&a[2]) && ma%3==2){
        cout<<ma/3+2<<"\n"; // optimal
    }else{
        if(present){
            cout<<ma/3+2<<"\n"; // optimal
        }else if(s.find(ma-1)==s.end()){
            cout<<ma/3 + 1<<"\n"; // optimal 
        }else{
            cout<<ma/3+2<<"\n"; // optimal
        }
    }
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