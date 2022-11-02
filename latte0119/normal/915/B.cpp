#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int n,pos,l,r;
    cin>>n>>pos>>l>>r;

    if(l==1&&r==n){
        cout<<0<<endl;
    }
    else if(l==1){
        cout<<abs(pos-r)+1<<endl;
    }
    else if(r==n){
        cout<<abs(pos-l)+1<<endl;
    }
    else{
        cout<<min(abs(pos-l),abs(pos-r))+r-l+2<<endl;
    }
    return 0;
}