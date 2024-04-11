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

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int N;
int A[111111];

signed main(){
    cin.tie(0);ios_base::sync_with_stdio(0);

    cin>>N;
    rep(i,N)cin>>A[i];

    int g=0;
    rep(i,N)g=gcd(g,A[i]);
    if(g>1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }

    int cnt=0;
    rep(i,N){
        if(A[i]%2==0)continue;
        if(A[i+1]%2){
            A[i+1]++;
            cnt++;
        }
        else{
            cnt+=2;
        }
    }
    cout<<"YES"<<endl;
    cout<<cnt<<endl;
    return 0;
}