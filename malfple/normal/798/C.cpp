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

int n;
int arr[100005];

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    rep(i,1,n)cin>>arr[i];

    bool allodd = true;
    rep(i,1,n)if(arr[i]%2 == 0){
        allodd = false;
        break;
    }

    int ans = -1;

    int totgcd = arr[1];
    rep(i,2,n)totgcd = gcd(totgcd, arr[i]);

    if(totgcd == 1){
        if(allodd)allodd = false;

        if(!allodd){
            ans = 0;
            int chainsize = 0;
            rep(i,1,n){
                if(arr[i]%2 == 0){
                    ans += chainsize/2 + 2*(chainsize&1);
                    chainsize = 0;
                }else{
                    chainsize++;
                }
            }
            ans += chainsize/2 + 2*(chainsize&1);
        }
    }else{
        ans = 0;
    }

    cout<<"YES"<<endl;
    cout<<ans<<endl;
    return 0;
}