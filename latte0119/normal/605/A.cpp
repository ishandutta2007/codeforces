#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int N;

int cnt[100000];

signed main(){
    scanf("%d",&N);
    rep(i,N){
        int p;
        scanf("%d",&p);
        p--;
        if(p)cnt[p]=cnt[p-1]+1;
        else cnt[p]=1;
    }

    int ma=0;
    rep(i,N)chmax(ma,cnt[i]);
    cout<<N-ma<<endl;
    return 0;
}