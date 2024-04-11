#include<bits/stdc++.h>
using namespace std;

//#define int long long

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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    vpint v;
    rep(i,3){
        int a,b;cin>>a>>b;v.pb(pint(a,b));
    }

    rep(b,1<<3){
        vpint vv=v;
        rep(i,3)if(b>>i&1)swap(vv[i].fi,vv[i].se);
        int p[3]={0,1,2};
        do{
            bool f=true;
            f&=vv[p[0]].fi==vv[p[1]].fi&&vv[p[1]].fi==vv[p[2]].fi;
            f&=vv[p[0]].se+vv[p[1]].se+vv[p[2]].se==vv[p[0]].fi;

            if(f){
                cout<<vv[p[0]].fi<<endl;
                rep(i,3){
                    rep(j,vv[p[i]].se){
                        rep(k,vv[p[0]].fi)cout<<(char)('A'+p[i]);cout<<endl;
                    }
                }
                return 0;
            }


            f=true;
            f&=vv[p[0]].fi==vv[p[1]].fi+vv[p[2]].fi;
            f&=vv[p[1]].se==vv[p[2]].se;
            f&=vv[p[0]].fi==vv[p[0]].se+vv[p[1]].se;
            if(f){
                cout<<vv[p[0]].fi<<endl;
                rep(i,vv[p[0]].se){
                    rep(j,vv[p[0]].fi)cout<<(char)('A'+p[0]);cout<<endl;
                }
                rep(i,vv[p[1]].se){
                    rep(j,vv[p[1]].fi)cout<<(char)('A'+p[1]);
                    rep(j,vv[p[2]].fi)cout<<(char)('A'+p[2]);
                    cout<<endl;
                }
                return 0;
            }
        }while(next_permutation(p,p+3));
    }

    cout<<-1<<endl;
    return 0;
}