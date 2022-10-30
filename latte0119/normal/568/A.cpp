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

const int LIM=3000000;
bool f[LIM];
bool g[LIM];
signed main(){
    fill_n(f,LIM,1);
    f[0]=f[1]=0;
    for(int i=2;i<LIM;i++){
        if(!f[i])continue;
        for(int j=i+i;j<LIM;j+=i)f[j]=0;
    }

    for(int i=1;i<LIM;i++){
        string s;
        stringstream ss;ss<<i;ss>>s;
        string t=s;
        reverse(all(t));
        g[i]=s==t;
    }

    int p,q;cin>>p>>q;
    int ma=0;
    int x=0,y=0;
    for(int i=1;i<LIM;i++){
        x+=f[i];
        y+=g[i];
        if(x*q<=p*y)ma=i;
    }

    if(ma==0)cout<<"Palindromic tree is better than splay tree"<<endl;
    else cout<<ma<<endl;
    return 0;
}