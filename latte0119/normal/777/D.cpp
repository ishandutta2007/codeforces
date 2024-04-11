#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

typedef unsigned long long ull;
ull p=999999937;

int N;
string S[555555];
vector<ull>H[555555];

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N;
    rep(i,N)cin>>S[i];

    rep(i,N){
        H[i].resize(S[i].size()+1);
        H[i][0]=0;
        for(int j=0;j<S[i].size();j++){
            H[i][j+1]=H[i][j]*p+S[i][j];
        }
    }

    vint len(N);len[N-1]=S[N-1].size();
    for(int i=N-2;i>=0;i--){
        int lim=min((int)S[i].size(),len[i+1]);
        int lb=1,ub=lim+1;
        while(ub-lb>1){
            int mid=(ub+lb)/2;
            if(H[i][mid]==H[i+1][mid])lb=mid;
            else ub=mid;
        }
        if(lb!=lim){
            if(S[i][lb]<S[i+1][lb])len[i]=S[i].size();
            else len[i]=lb;
        }
        else if(lb==len[i+1]){
            len[i]=len[i+1];
        }
        else{
            len[i]=S[i].size();
        }
    }

    rep(i,N)cout<<S[i].substr(0,len[i])<<endl;
    return 0;
}