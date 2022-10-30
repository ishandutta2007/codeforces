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

bool isp(int n){
    for(int i=2;i*i<=n;i++)if(n%i==0)return false;
    return true;
}

signed main(){
    int N;
    cin>>N;
    if(N==2){
        cout<<1<<endl;
        return 0;
    }
    if(N%2==0){
        cout<<2<<endl;
        return 0;
    }

    if(isp(N)){
        cout<<1<<endl;
        return 0;
    }

    if(isp(N-2)){
        cout<<2<<endl;
        return 0;
    }
    cout<<3<<endl;
    return 0;
}