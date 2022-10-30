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

const int len=20000;
int T[50];
char S[50][10];
signed main(){
    int N;
    scanf("%lld",&N);
    rep(i,N)scanf("%lld%s",&T[i],S[i]);

    int y=0;
    rep(i,N){
        int d;
        if(S[i][0]=='N')d=0;
        else if(S[i][0]=='E')d=1;
        else if(S[i][0]=='S')d=2;
        else d=3;

        if(d==1||d==3){
            if(y==0||y==len){
                puts("NO");
                return 0;
            }
            continue;
        }
        if(d==0)y-=T[i];
        else y+=T[i];
        if(y<0||y>len){
            puts("NO");
            return 0;
        }
    }

    if(y==0)puts("YES");
    else puts("NO");
    return 0;
}