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

signed main(){
    int N,S;
    scanf("%lld%lld",&N,&S);
    S--;
    int ans=0;
    vint A(N);
    rep(i,N)scanf("%lld",&A[i]);
    deque<int>s;
    rep(i,N){
        if(i==S){
            if(A[i]){
                A[i]=0;
                ans++;
            }
        }
        else{
            if(A[i]==0){
                A[i]=INT_MAX;
            }
            s.push_back(A[i]);
        }
    }
    sort(all(s));

    for(int i=1;s.size();i++){
        if(s.front()>i){
            ans++;
            s.pop_back();
        }
        else{
            while(s.size()&&s.front()==i)s.pop_front();
        }
    }
    cout<<ans<<endl;
    return 0;
}