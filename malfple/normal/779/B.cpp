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

int main(){
    int n,k;
    cin>>n>>k;

    //zero case
    int zero = 0;
    int tn = n;
    bool zeroexist = false;
    while(tn){
        if(tn % 10 == 0)zeroexist = true;
        zero++;
        tn/=10;
    }
    if(zeroexist)zero--;

    //the rest
    int ans = 0;
    tn = n;
    while(k){
        if(tn == 0){
            ans = 100;
            break;
        }
        if(tn%10 == 0)k--;
        else ans++;
        tn /= 10;
    }

    printf("%d\n", min(ans, zero));
    return 0;
}