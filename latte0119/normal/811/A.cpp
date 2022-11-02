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
    int a,b;
    cin>>a>>b;

    int ans=LLONG_MAX;
    for(int i=1;;i++){
        if(i*i>a){
            chmin(ans,i*2-1);
            break;
        }

    }

    for(int i=1;;i++){
        if(i*(i+1)>b){
            chmin(ans,i*2);
            break;
        }
    }

    if(ans&1)cout<<"Vladik"<<endl;
    else cout<<"Valera"<<endl;

    return 0;
}