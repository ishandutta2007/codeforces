#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

const int N = 205;
const int B5 = 26*N;

int n,k;
int f2[N];
int f5[N];
int dp[N][B5];
int S5;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>k;
    REP(i,1,n){
        ll x;
        cin>>x;
        while(x%2 == 0){
            x /= 2;
            f2[i]++;
        }
        while(x%5 == 0){
            x /= 5;
            f5[i]++;
        }
        S5 += f5[i];
    }

    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    REP(i,1,n){
        //printf("%d ===\n",i);
        REV(j,k,0){
            REV(s5, S5, 0){
                //take
                if(j>0 && s5 >= f5[i] && dp[j-1][s5-f5[i]] != -1)
                    dp[j][s5] = max(dp[j][s5], dp[j-1][s5-f5[i]] + f2[i]);
                //printf("%d ",dp[next][j][s5]);
            }
            //printf("\n");
        }
    }

    /*REP(i,1,n){
        REP(s5,0,S5)printf("%d ",dp[i][k][s5]);
        printf("\n");
    }*/

    int ans = 0;
    REP(s5,0,S5)ans = max(ans, min(s5, dp[k][s5]));
    cout << ans << endl;

    return 0;
}