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
    int N,M,A,D;
    cin>>N>>M>>A>>D;
    N++;
    vint T(M);rep(i,M)cin>>T[i];

    int K=D/A+1;

    int ans=0;
    int x=1,y=0;

    while(x<N||y<M){
        if(y==M){
            ans+=(N-x+K-1)/K;
            break;
        }
        if(x==N){
            int nex=y;
            while(nex<M&&T[nex]-T[y]<=D)nex++;
            y=nex;
            ans++;
            continue;
        }


        if(A*x<=T[y]){
            int k=(T[y]-A*x)/(K*A);
            chmin(k,(N-x+K-1)/K-1);
            ans+=k+1;

            int nex=y;
            while(nex<M&&T[nex]<=A*(x+k*K)+D)nex++;
            y=nex;
            x+=(k+1)*K;
            chmin(x,N);
        }
        else{
            if(A*x<=T[y]+D){
                int k=(T[y]+D-A*x)/A+1;
                x+=k;
                chmin(x,N);
            }

            int nex=y;
            while(nex<M&&T[nex]-T[y]<=D)nex++;
            y=nex;
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}