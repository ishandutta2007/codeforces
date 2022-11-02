#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int N;
int A[5000];

int ans[5000];
int cnt[5000];
signed main(){
    cin>>N;
    rep(i,N)cin>>A[i],A[i]--;

    rep(i,N){
        int ma=A[i];
        ans[ma]++;
        memset(cnt,0,sizeof(cnt));
        cnt[ma]++;
        reps(j,i+1,N){
            cnt[A[j]]++;
            if(cnt[A[j]]>cnt[ma]||(cnt[A[j]]==cnt[ma]&&A[j]<ma)){
                ma=A[j];
            }
            ans[ma]++;
        }
    }
    rep(i,N)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}