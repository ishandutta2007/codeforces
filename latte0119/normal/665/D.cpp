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

bool f[2222222];
map<int,int>cnt;
signed main(){
    fill_n(f,2222222,true);
    f[0]=f[1]=false;
    for(int i=2;i<2222222;i++){
        if(!f[i])continue;
        for(int j=i*2;j<2222222;j+=i)f[j]=false;
    }

    int N;
    cin>>N;
    rep(i,N){
        int a;cin>>a;cnt[a]++;
    }

    each(it,cnt){
        if(!f[it->fi*2]){
            it->se=1;
        }
    }

    pint u,v;
    each(i,cnt){
        each(j,cnt){
            if(i->fi==j->fi){
                if(u.se+v.se<i->se){
                    u=*i;
                    v=pint(0,0);
                }
            }
            else if(u.se+v.se<i->se+j->se&&f[i->fi+j->fi]){
                    u=*i;
                    v=*j;
            }

        }
    }

    cout<<u.se+v.se<<endl;
    rep(i,u.se)cout<<u.fi<<" ";
    rep(i,v.se)cout<<v.fi<<" ";
    cout<<endl;
    return 0;
}