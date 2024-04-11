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
    int d;
    bool f = 1;
    ll ans = 0;
    int odd = 0;
    int even = 0;
    cin>>d;
    for(int i=0;i<n-2;i++){
        cin>>d;
        if(d!=1) f = 0;
        if(d%2==1) odd++;
        else even++;
        ans+=(d+1)/2; 
    }
    cin>>d;
    if((odd==1 && even==0) || f){
        cout<<-1<<"\n";
    }else{
        cout<<ans<<"\n";
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
/*
    a 1 1 1  ...... b not solvable 
    a 1 2 1 ........ b solvable 
    a 1 3 1 1 ........ b solvable 
    a 1 3 b -> 
    a 2 1 b+1
    a+1 0 2 b+1 
    a+2 0 0 b+2 

    No if all 1's or a single odd element in b/w 
    a 2 3 b 

    all reduce to 1's and 2's 
    all even -> number of 2's 
    atleast 1 even -> all 2's + num of odds 
    all odds 
    a 1 1 1 1 2 1 2 b 1 + alreas 1 even case 
    a 1 3 b
    a 2 1 b
    a 0 2 b
    a 0 0 b


    a 1 3 1 b
    a 2 1 2 b
    a 2 1 0 b
    a 0 2 0 b
    a 0 0 0 b

*/