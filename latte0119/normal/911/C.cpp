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
    int K[3];
    rep(i,3)cin>>K[i];sort(K,K+3);
    if(K[0]==1){
        cout<<"YES"<<endl;
        return 0;
    }

    if(K[0]==2){
        if(K[1]==2){
            cout<<"YES"<<endl;
            return 0;
        }
        if(K[1]==4&&K[2]==4){
            cout<<"YES"<<endl;
            return 0;
        }
        cout<<"NO"<<endl;
        return 0;
    }
    if(K[0]==3){
        if(K[1]==3&&K[2]==3){
            cout<<"YES"<<endl;
            return 0;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}