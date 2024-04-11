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
    int K;cin>>K;

    string S;
    for(char c='a';c<='z';c++){
        int k=0;
        while(k*(k+1)/2<=K)k++;
        S+=string(k,c);
        K-=k*(k-1)/2;
    }
    cout<<S<<endl;
    return 0;
}