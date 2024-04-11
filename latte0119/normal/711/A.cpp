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
    int N;
    cin>>N;
    vector<string>S(N);
    rep(i,N)cin>>S[i];

    rep(i,N){
        rep(j,2){
            int a=j*3;
            int b=a+1;
            if(S[i][a]=='O'&&S[i][b]=='O'){
                S[i][a]=S[i][b]='+';
                cout<<"YES"<<endl;
                rep(k,N)cout<<S[k]<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;
}