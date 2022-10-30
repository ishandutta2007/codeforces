#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int f[2222222];

signed main(){
    fill_n(f,2222222,1);
    f[0]=f[1]=0;
    for(int i=2;i<2222222;i++){
        if(!f[i])continue;
        for(int j=i+i;j<2222222;j+=i)f[j]=0;
    }

    int n;cin>>n;
    for(int i=1;;i++){
        if(f[n*i+1]==0){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}