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

const int N = 400005;

int n,k;
int arr[N];
int next[N];
map<int,int> mep;

priority_queue<pii>pq;
bool have[N];
int excess = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    rep(i,1,n)cin>>arr[i];
    rev(i,n,1){
        if(mep.find(arr[i]) == mep.end()){
            next[i] = OO;
            mep[arr[i]] = i;
        }else{
            next[i] = mep[arr[i]];
            mep[arr[i]] = i;
        }
    }

    //rep(i,1,n)cout << next[i] << " ";
    //cout << endl;

    int ans = 0;
    rep(i,1,n){
        if(have[arr[i]]){
            excess++;
            pq.push(mp(next[i], arr[i]));
            continue;
        }

        //delete book
        if(pq.size() == k+excess){
            //printf("delete %d\n",pq.top().ss);
            have[pq.top().ss] = false;
            pq.pop();
        }

        // buy
        ans++;
        //printf("buy %d\n",arr[i]);
        have[arr[i]] = true;
        pq.push(mp(next[i], arr[i]));
    }
    cout << ans << endl;
    return 0;
}