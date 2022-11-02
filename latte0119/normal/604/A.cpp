#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}


signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int m[5],w[5];
    rep(i,5)cin>>m[i];
    rep(i,5)cin>>w[i];
    int X,Y;cin>>X>>Y;

    int ans=0;
    rep(i,5){
        int v=(i+1)*500;
        int a=v*3/10;
        int b=(250-m[i])*v/250-50*w[i];
        ans+=max(a,b);
    }
    ans+=X*100-Y*50;
    cout<<ans<<endl;
    return 0;
}