#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N,M;

int X[100000],Y[100000];

signed main(){
    scanf("%lld%lld",&N,&M);
    vector<pair<pint,int> >st(M);
    rep(i,M)scanf("%lld%lld",&st[i].first.first,&st[i].first.second);
    rep(i,M)st[i].first.second^=1;
    rep(i,M)st[i].second=i;
    sort(all(st));


    int cnt=0,cur=2,idx=0,sum=0,s=0;

    rep(i,M){
        int w=st[i].first.first,f=st[i].first.second,id=st[i].second;
        if(f==0){
            X[id]=0;
            sum+=cnt;
            Y[id]=++cnt;
            continue;
        }
        if(sum==s){
            cout<<-1<<endl;
            return 0;
        }
        s++;
        idx++;
        if(cur==idx){
            cur++;
            idx=1;
        }
        X[id]=cur;
        Y[id]=idx;
    }

    rep(i,M)printf("%lld %lld\n",X[i]+1,Y[i]+1);
    return 0;
}