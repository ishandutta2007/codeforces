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

int N,M;
int T[5555],A[5555],B[5555],C[5555];

int sum[5555],a[5555];

signed main(){
    cin>>N>>M;
    rep(i,M)cin>>T[i]>>A[i]>>B[i]>>C[i],A[i]--;

    fill_n(a,5555,1000000000);

    for(int i=0;i<M;i++){
        if(T[i]==1){
            for(int j=A[i];j<B[i];j++)sum[j]+=C[i];
        }
        else{
            for(int j=A[i];j<B[i];j++)chmin(a[j],C[i]-sum[j]);
        }
    }

    vint b(N);rep(i,N)b[i]=a[i];

    if(*min_element(a,a+N)<-1000000000){
        cout<<"NO"<<endl;
        return 0;
    }
    
    rep(i,M){
        if(T[i]==1){
            for(int j=A[i];j<B[i];j++)a[j]+=C[i];
        }
        else if(*max_element(a+A[i],a+B[i])!=C[i]){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    rep(i,N){
        if(i)cout<<" ";
        cout<<b[i];
    }cout<<endl;
    return 0;
}