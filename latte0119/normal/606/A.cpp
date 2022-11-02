#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int a[3],b[3];

int main(){
    rep(i,3)cin>>a[i];
    rep(i,3)cin>>b[i];

    int x=0;
    rep(i,3){
        if(a[i]>=b[i])x+=(a[i]-b[i])/2;
        else x-=(b[i]-a[i]);
    }
    if(x>=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}