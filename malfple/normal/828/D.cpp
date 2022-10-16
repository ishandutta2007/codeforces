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

int n,m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>m;

    if(n-m == 1){
        cout << 2 << endl;
        rep(i,2,n)cout << "1 " << i << endl;
    }else if(n-m == 2){
        cout << 3 << endl;
        cout << "1 2" << endl;
        cout << "1 3" << endl;
        rep(i,4,n)cout << "2 " << i << endl;
    }else{
        int nonexit = n-m;
        int legs = min(m, nonexit-1);
        int len = (nonexit-1) / legs;
        int mn = len;
        if((nonexit-1)%legs != 0)len++;
        mn *= 2;
        if((nonexit-1)%legs == 0)mn = mn;
        else if((nonexit-1)%legs == 1)mn++;
        else mn+=2;
        mn += 2;

        cout << mn << endl;

        int exitnow = nonexit+1;
        int curr = 2;
        rep(i,1,legs){
            int prev = 1;
            rep(j,1,len){
                if(curr+legs-i > nonexit)break;
                cout << prev << " " << curr << endl;
                prev = curr;
                curr++;
            }
            cout << prev << " " << exitnow << endl;
            exitnow++;
        }
        while(exitnow <= n)cout << "1 " << exitnow++ << endl;
    }

    return 0;
}