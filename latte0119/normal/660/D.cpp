#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,f,n) for(int i=(int)(f);i<(int)(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
int x[2222],y[2222];

signed main(){
    cin>>N;
    rep(i,N)cin>>x[i]>>y[i];

    map<pint,int>M;
    rep(i,N)reps(j,i+1,N){
        int dx=x[i]-x[j];
        int dy=y[i]-y[j];
        if(dx<0){
            dx*=-1;dy*=-1;
        }
        else if(dx==0&&dy<0){
            dy*=-1;
        }

        M[pint(dy,dx)]++;
    }

    int ans=0;
    each(it,M){
        ans+=it->se*(it->se-1)/2;
    }
    cout<<ans/2<<endl;
    return 0;
}