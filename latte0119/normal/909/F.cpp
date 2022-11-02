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

vint hoge={7,6,2,5,4,3,1};
vint piyo={3,6,2,5,1,4};
vint solve2(int N){
    if(N%2){
        if(N<=5)return vint();
        vint a=hoge;
        for(int i=8;i<=N;i++){
            a.pb(i^1);
        }
        return a;
    }

    if(N==6)return piyo;
    for(int i=2;i<=N;i*=2)if(i==N)return vint();

    vint a=solve2(N-1);
    for(int i=8;i<N;i+=2){
        if((i&N)==0)continue;
        a[i-1]=N;
        a.pb(i+1);
        return a;
    }

    if(N>>2&1){
        a[3]=N;
        a.pb(5);
        return a;
    }
    if(N>>1&1){
        a[5]=N;
        a.pb(3);
        return a;
    }
}

bool check2(vint a){
    for(int i=0;i<a.size();i++)if(a[i]==i+1||((i+1)&(a[i]))==0)return false;
    return true;
}

vint solve(int N){
    if(N%2||N==0)return vint();
    int x=1;
    while(x*2<=N)x*=2;
    int tmp=N-x+1;
    vint a=solve(N-2*tmp);
    for(int i=0;i<tmp*2;i++){
        a.pb(N-i);
    }
    return a;
}

bool check(vint a){
    rep(i,a.size())if(a[i]==i+1||((i+1)&a[i])!=0)return false;
    return true;
}

signed main(){
    int n;cin>>n;

    vint a,b;
    a=solve(n);b=solve2(n);
    rep(t,2){
        if(a.size()==0)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            rep(i,a.size()){
                if(i)cout<<" ";
                cout<<a[i];
            }cout<<endl;
        }
        swap(a,b);
    }
    return 0;
}