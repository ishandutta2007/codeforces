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

int arr[10005];
int cnta[10005];
int cntb[10005];

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;

    bool fail = false;
    rep(i,1,m){
        int a;
        cin>>a;
        rep(j,1,a)cin>>arr[j];

        bool success = false;
        rep(j,1,a){
            if(arr[j] > 0){
                if(cntb[arr[j]] > 0)success = true;
                cnta[arr[j]]++;
            }else{
                if(cnta[-arr[j]] > 0)success = true;
                cntb[-arr[j]]++;
            }
        }
        rep(j,1,a){
            if(arr[j] > 0){
                cnta[arr[j]]--;
            }else{
                cntb[-arr[j]]--;
            }
        }

        if(!success){
            fail = true;
            //printf("FALSE\n");
        }
    }

    if(fail)printf("YES\n");
    else printf("NO\n");
    return 0;
}