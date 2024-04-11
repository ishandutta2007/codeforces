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
    int N;cin>>N;
    vint A(N);rep(i,N)cin>>A[i];

    int sum=accumulate(all(A),0ll);
    if(sum){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<" "<<N<<endl;
        return 0;
    }

    int s=0;
    for(int i=0;i<N-1;i++){
        s+=A[i];
        if(s){
            cout<<"YES"<<endl;
            cout<<2<<endl;
            cout<<1<<" "<<i+1<<endl;
            cout<<i+2<<" "<<N<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}