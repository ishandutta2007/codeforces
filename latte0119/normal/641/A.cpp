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

int N;
string S;
int D[111111];

bool used[111111];

signed main(){
    cin>>N;
    cin>>S;
    rep(i,N)cin>>D[i];

    used[0]=1;
    int v=0;
    while(true){
        int u;
        if(S[v]=='<')u=v-D[v];
        else u=v+D[v];
        if(u<0||u>=N){
            cout<<"FINITE"<<endl;
            return 0;
        }
        if(used[u])break;
        used[u]=true;
        v=u;
    }

    cout<<"INFINITE"<<endl;
    return 0;
}