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

int N,A,B;
int fld[111][111];
signed main(){
    cin>>N>>A>>B;
    if(N>A*B){
        cout<<-1<<endl;
        return 0;
    }
    int o=1,e=2;
    rep(i,A){
        rep(j,B){
            if((i+j)%2==0&&o<=N){
                cout<<o<<" ";
                o+=2;
            }
            else if((i+j)%2&&e<=N){
                cout<<e<<" ";
                e+=2;
            }
            else cout<<0<<" ";
        }
        cout<<endl;
    }

    return 0;
}