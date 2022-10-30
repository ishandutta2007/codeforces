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
    int N;string S;
    cin>>N>>S;

    int cur=0;
    int ans=0;
    int ans2=0;
    bool in=false;
    while(cur<N){
        if(S[cur]=='_'){
            cur++;
            continue;
        }
        if(S[cur]=='('){
            in=true;
            cur++;
            continue;
        }
        if(S[cur]==')'){
            in=false;
            cur++;
            continue;
        }

        if(in){
            if(!isalpha(S[cur-1]))ans2++;
            cur++;
            continue;
        }
        int next=cur;
        while(next<N&&isalpha(S[next]))next++;
        chmax(ans,next-cur);
        cur=next;
    }

    cout<<ans<<" "<<ans2<<endl;
    return 0;
}