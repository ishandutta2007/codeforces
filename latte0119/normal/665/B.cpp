#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M,K;
int A[111];

signed main(){
    cin>>N>>M>>K;
    rep(i,K)cin>>A[i];

    int cnt=0;
    while(N--){
        rep(hoge,M){
            int p;cin>>p;
            p=find(A,A+K,p)-A;
            cnt+=p+1;
            while(p){
                swap(A[p],A[p-1]);
                p--;
            }
        }
    }

    cout<<cnt<<endl;
    return 0;
}