#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int T,N;

int calc(){
    int ret=0;
    rep(i,N){
        int a,b;
        cin>>a>>b;
        if(a||b)ret++;
    }
    return ret;
}

int main(){
    cin>>T>>N;
    int ans=0;
    while(T--)ans+=calc();
    cout<<ans<<endl;
    return 0;
}