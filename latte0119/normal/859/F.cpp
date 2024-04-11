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

struct data{
    int l,r,s;
    data(int l,int r,int s):l(l),r(r),s(s){}
};

signed main(){
    int N,C;cin>>N>>C;

    deque<data>d;
    int dx=0,dy=0;

    vint T(N);
    vint A(2*N);
    rep(i,2*N-1)cin>>A[i];

    T[0]=min(C,A[0]);
    d.pb(data(0,T[0],0));
    for(int i=1;i<N;i++){
        dx+=A[i*2-1];
        dy+=A[i*2-1];
        if(A[i*2-1])d.push_front(data(-dx,A[i*2-1]-dx,-dy));
        while(d.size()&&d.front().l+dx<T[i-1]){
            if(d.front().r+dx<=T[i-1]){
                d.pop_front();
            }
            else{
                d.front().s+=T[i-1]-(d.front().l+dx);
                d.front().l=T[i-1]-dx;
            }
        }
        dx-=T[i-1];

        dx+=A[i*2];
        dy+=A[i*2];
        if(A[i*2])d.push_front(data(-dx,A[i*2]-dx,-dy));
        while(d.size()&&d.back().s+dy+d.back().r-d.back().l>C){
            if(d.back().s+dy>=C)d.pop_back();
            else d.back().r=C-(d.back().s+dy)+d.back().l;
        }
        if(d.size())T[i]=d.back().r+dx;
    }

    cout<<accumulate(all(T),0ll)<<endl;
    return 0;
}