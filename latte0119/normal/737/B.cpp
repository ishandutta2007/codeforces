#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,A,B,K;

signed main(){
    cin>>N>>A>>B>>K;
    string S;
    cin>>S;
    vint v;
    int cur=0;
    while(cur<N){
        if(S[cur]=='1')cur++;
        else{
            int next=cur;
            while(next<N&&next-cur<B&&S[next]=='0')next++;
            if(next-cur==B)v.pb(next-1);
            cur=next;
        }
    }

    assert(v.size()>=A);
    int aim=v.size()-(A-1);
    printf("%lld\n",aim);
    rep(i,aim)printf("%lld ",v[i]+1);
    puts("");
    return 0;
}