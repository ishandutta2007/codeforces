#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;
vint v[10000];
string S[100000];
int C[100000],A[100000];

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N>>M;
    rep(i,N){
        cin>>S[i]>>C[i]>>A[i];
        C[i]--;
        v[C[i]].pb(i);
    }

    rep(i,M){
        vpint st;
        for(int j:v[i])st.pb(pint(A[j],j));
        sort(all(st));reverse(all(st));

        if(st.size()==2||st[1].fi!=st[2].fi){
            cout<<S[st[0].se]<<" "<<S[st[1].se]<<endl;
        }
        else cout<<"?"<<endl;
    }
    return 0;
}