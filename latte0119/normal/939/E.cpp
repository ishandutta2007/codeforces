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

typedef long double ld;

struct CHT{
    deque<pair<ld,ld>>ls;
    inline bool check(const pair<ld,ld>&a,const pair<ld,ld>&b,const pair<ld,ld>&c){
        return (b.fi-a.fi)*(c.se-b.se)>=(b.se-a.se)*(c.fi-b.fi);
    }
    void add(ld a,ld b){
        pair<ld,ld>l(a,b);
        while(ls.size()>=2&&check(ls[ls.size()-2],ls[ls.size()-1],l))ls.pop_back();
        ls.push_back(l);
    }
    ld query(ld x){
        assert(ls.size());
        while(ls.size()>1&&ls[0].fi*x+ls[0].se>=ls[1].fi*x+ls[1].se)ls.pop_front();
        return ls[0].fi*x+ls[0].se;
    }
};

int Q;

signed main(){
    scanf("%lld",&Q);

    int n=0;
    int sum=0;
    int M=0;

    CHT cht;
    while(Q--){
        int t;scanf("%lld",&t);
        if(t==1){
            int s;scanf("%lld",&s);
            sum+=M;
            n++;
            cht.add(1.0/n,1.0*sum/n);
            M=s;
        }
        else{
            printf("%.20Lf\n",M-cht.query(M));
        }
    }
    return 0;
}