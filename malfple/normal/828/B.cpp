#include <iostream>
#include <cstdio>

#include <cstring>
#include <string>

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

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

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

int arr[105][105];

int get(int x,int y, int c){
    return arr[x][y] - arr[x-c][y] - arr[x][y-c] + arr[x-c][y-c];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    int n,m;
    cin>>n>>m;
    int blacks = 0;
    rep(i,1,n){
        rep(j,1,m){
            char x;
            cin>>x;
            if(x == 'B'){
                blacks++;
                arr[i][j] = 1;
            }
        }
    }

    rep(i,1,n)rep(j,2,m)arr[i][j] += arr[i][j-1];
    rep(j,1,m)rep(i,2,n)arr[i][j] += arr[i-1][j];

    int mn = -1;
    rep(k,1,min(n,m)){
        rep(i,k,n){
            rep(j,k,m){
                int now = get(i,j,k);
                //printf("%d %d %d now: %d\n",i,j,k,now);
                if(now == blacks){
                    mn = k;
                    goto hell;
                }
            }
        }
    }
    hell:

    if(mn == -1)cout << -1 << endl;
    else cout << mn*mn - blacks << endl;
    return 0;
}