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

int N;
int A[50000];
int ans[50000];
bool C(int x){
    priority_queue<pint>que;
    rep(i,N){
        int a=A[i];
        while(a>x)a/=2;
        que.push(pint(a,1));
    }

    int r=0;
    while(que.size()){
        int v=que.top().fi;
        if(v==0)return false;
        int cnt=0;
        while(que.size()&&que.top().fi==v){
            cnt+=que.top().se;
            que.pop();
        }
        ans[r++]=v;
        if(cnt==1)continue;
        cnt--;
        que.push(pint(v/2,cnt));
    }

    return true;
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&A[i]);

    int lb=-1,ub=INT_MAX;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid))ub=mid;
        else lb=mid;
    }

    C(ub);
    rep(i,N)printf("%lld ",ans[i]);
    return 0;
}