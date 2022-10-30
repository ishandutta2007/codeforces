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

int N;
char S[1111111];


int sumU[1111111],sumD[1111111];

signed main(){
    scanf("%lld",&N);
    scanf("%s",S);

    int U=0,D=0;
    for(int i=N-1;i>=0;i--){
        if(S[i]!='D')continue;
        sumD[D+1]=sumD[D]+i;
        D++;
    }
    rep(i,N){
        if(S[i]=='D'){
            D--;
        }

        int val;
        if(S[i]=='U'){
            if(D<=U){
                val=(sumD[D]-i*D)*2+(i*D-sumU[U]+sumU[U-D])*2+N-i;
            }
            else{
                val=(sumD[D]-sumD[D-U-1]-i*(U+1))*2+(i*U-sumU[U])*2+i+1;
            }
        }
        else{
            if(U<=D){
                val=(i*U-sumU[U])*2+(sumD[D]-sumD[D-U]-i*U)*2+i+1;
            }
            else{
                val=(i*(D+1)-sumU[U]+sumU[U-D-1])*2+(sumD[D]-i*D)*2+N-i;
            }
        }
        printf("%lld ",val);

        if(S[i]=='U'){
            sumU[U+1]=sumU[U]+i;
            U++;
        }
    }
    return 0;
}