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

int p,x,y;

bool cek(int s){
    int i = (s / 50) % 475;
    rep(j,1,25){
        i = (i * 96 + 42) % 475;
        if(p == 26 + i)return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>p>>x>>y;

    int ans = -1;
    revv(i,x,y,50){
        if(cek(i)){
            ans = 0;
            break;
        }
    }

    if(ans == -1){
        rep(i,0,475){
            if(cek(x)){
                ans = (i+1)/2;
                break;
            }
            x += 50;
        }
    }

    cout << ans << endl;

    return 0;
}