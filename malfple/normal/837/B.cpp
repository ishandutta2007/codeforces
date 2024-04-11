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

const int N = 105;

int n,m;
char arr[N][N];
vector<char>v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    v.pb('R'); v.pb('G'); v.pb('B');

    cin>>n>>m;
    REP(i,1,n)REP(j,1,m)cin>>arr[i][j];

    bool can = false;
    if(n%3 == 0){
        int athird = n/3;
        sort(v.begin(), v.end());
        do{
            bool rekt = false;
            FOR(k,3){
                REP(i,1 + k*athird, (k+1)*athird){
                    REP(j,1,m){
                        if(arr[i][j] != v[k])rekt = true;
                    }
                }
            }
            if(!rekt)can = true;
        }while(next_permutation(v.begin(), v.end()));
    }
    if(m%3 == 0){
        int athird = m/3;
        sort(v.begin(), v.end());
        do{
            bool rekt = false;
            FOR(k,3){
                REP(i,1 + k*athird, (k+1)*athird){
                    REP(j,1,n){
                        if(arr[j][i] != v[k])rekt = true;
                    }
                }
            }
            if(!rekt)can = true;
        }while(next_permutation(v.begin(), v.end()));
    }

    if(can)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}