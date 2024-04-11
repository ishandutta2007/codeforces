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

bool solve(int N){

    for(int A=N/2+1;A<N;A++){
        int tmp=2*A-N;
        for(int j=1;j<tmp;j++){
            int k=tmp-j;
            if(k<=j)break;
            if(A%j||A%k)continue;
            if(A==A*N/k||A*N/k==A*N/j||A*N/j==A)continue;
            cout<<A<<" "<<A*N/k<<" "<<A*N/j<<endl;
            return true;
        }
    }
    return false;
}

signed main(){
    int N;
    cin>>N;
    if(N==1){
        cout<<-1<<endl;
    return 0;
    }
    if(N%2==0){
        N/=2;
        cout<<2*N<<" "<<3*N<<" "<<6*N<<endl;
        return 0;
    }
    if(N==3){
        cout<<"2 7 42"<<endl;
        return 0;
    }
    solve(N);
    return 0;
}