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
    cin.tie(0);ios_base::sync_with_stdio(0);

    int A,B,C;cin>>A>>B>>C;
    int N;cin>>N;
    vint X,Y;
    rep(i,N){
        int a;
        string s;
        cin>>a>>s;
        if(s=="USB")X.pb(a);
        else Y.pb(a);
    }
    X.pb(0);Y.pb(0);
    sort(all(X));sort(all(Y));
    for(int i=0;i+1<X.size();i++)X[i+1]+=X[i];
    for(int i=0;i+1<Y.size();i++)Y[i+1]+=Y[i];

    int cnt=0,sum=0;
    for(int i=0;i<Y.size()&&i<=B+C;i++){
        int tmp=A+C-max(0ll,i-B);
        chmin(tmp,X.size()-1);
        if(cnt<tmp+i){
            cnt=tmp+i;
            sum=X[tmp]+Y[i];
        }
        else if(cnt==tmp+i)chmin(sum,X[tmp]+Y[i]);
    }

    cout<<cnt<<" "<<sum<<endl;
    return 0;
}