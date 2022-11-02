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

int N;
int A[300000];

signed main(){
    cin>>N;
    rep(i,N)cin>>A[i];
    set<int>s;
    vpint ans;
    int l=0;
    rep(i,N){
        if(s.find(A[i])!=s.end()){
            ans.pb(pint(l,i));
            s.clear();
            l=i+1;
        }
        else{
            s.insert(A[i]);
        }
    }

    if(ans.size()==0){
        cout<<-1<<endl;
        return 0;
    }
    ans[ans.size()-1].se=N-1;
    cout<<ans.size()<<endl;
    rep(i,ans.size())cout<<ans[i].fi+1<<" "<<ans[i].se+1<<endl;
    return 0;
}