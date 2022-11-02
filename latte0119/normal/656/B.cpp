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
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

bool ng[360360];

int N;
int M[111],R[111];

signed main(){
    cin>>N;
    rep(i,N)cin>>M[i];
    rep(i,N)cin>>R[i];

    rep(i,N){
        int a=R[i];
        while(a<360360){
            ng[a]=true;
            a+=M[i];
        }
    }

    int cnt=0;
    rep(i,360360)cnt+=ng[i];

    printf("%.20f\n",cnt/360360.0);
    return 0;
}