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
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

const int SIZE=500010;
int N,M,P;
char S[SIZE];
int to[SIZE];
int L[SIZE],R[SIZE];


signed main(){
    scanf("%lld%lld%lld",&N,&M,&P);
    scanf("%s",S+1);

    stack<int>s;
    for(int i=1;i<=N;i++){
        if(S[i]=='('){
            s.push(i);
        }
        else{
            to[i]=s.top();
            to[s.top()]=i;
            s.pop();
        }
    }

    for(int i=0;i<=N+1;i++)L[i]=i-1;
    for(int i=0;i<=N+1;i++)R[i]=i+1;

    int cur=P;

    while(M--){
        char c;
        scanf(" %c",&c);
        if(c=='L'){
            cur=L[cur];
        }
        else if(c=='R'){
            cur=R[cur];
        }
        else{
            if(S[cur]==')')cur=to[cur];
            R[L[cur]]=R[to[cur]];
            L[R[to[cur]]]=L[cur];
            if(R[to[cur]]!=N+1)cur=R[to[cur]];
            else cur=L[cur];
        }
    }


    cur=0;
    while(R[cur]!=N+1){
        cur=R[cur];
        printf("%c",S[cur]);
    }
    puts("");
    return 0;
}