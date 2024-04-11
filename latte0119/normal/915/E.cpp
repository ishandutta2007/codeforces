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
    int N,Q;scanf("%lld%lld",&N,&Q);

    set<pint>s;
    s.insert(pint(0,N));
    int cnt=N;
    while(Q--){
        int l,r,k;
        scanf("%lld%lld%lld",&l,&r,&k);
        l--;
            while(true){
                auto it=s.lower_bound(pint(l,-1));
                if(it==s.end())break;
                pint p=*it;
                if(p.fi>=r)break;
                s.erase(it);cnt-=p.se-p.fi;
                if(p.se>r){
                    s.insert(pint(r,p.se));cnt+=p.se-r;
                }
            }
            auto it=s.lower_bound(pint(l,-1));

            if(it!=s.begin()){
                it--;
                pint p=*it;
                if(p.se>l){
                    s.erase(it);cnt-=p.se-p.fi;
                    s.insert(pint(p.fi,l));cnt+=l-p.fi;
                }
                if(p.se>r){
                    s.insert({r,p.se});cnt+=p.se-r;
                }
            }

        if(k==2)s.insert(pint(l,r)),cnt+=r-l;
        printf("%lld\n",cnt);
    }
}