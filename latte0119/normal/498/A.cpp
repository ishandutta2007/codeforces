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

int latte(int a,int b,int c,int x,int y){
    if(b==0){
        if(a<0){
            a*=-1;c*=-1;
        }
        return a*x<-c;
    }
    if(b<0){
        a*=-1;b*=-1;c*=-1;
    }

    return y*b<(-a*x-c);
}

signed main(){
    int x,y,xx,yy;
    cin>>x>>y>>xx>>yy;

    int n;cin>>n;
    int ans=0;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        if(latte(a,b,c,x,y)!=latte(a,b,c,xx,yy))ans++;
    }
    cout<<ans<<endl;
    return 0;
}