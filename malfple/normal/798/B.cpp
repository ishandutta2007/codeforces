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
string arr[55];
int cnt[55];

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    rep(i,1,n)cin>>arr[i];
    int m = arr[1].size();

    bool rekt = false;
    rep(i,2,n){
        if(arr[i].size() != m)rekt = true;
        if(arr[i] == arr[1])continue;
        bool found = false;
        rep(j,1,m-1){
            arr[i]+= arr[i][0];
            arr[i].erase(0,1);
            //cout<<arr[i]<<endl;
            cnt[i]++;
            if(arr[i] == arr[1]){
                found = true;//cout<<"ye"<<endl;
                break;
            }
        }
        if(!found)rekt = true;
        if(rekt)break;
    }

    if(rekt)cout<<-1<<endl;
    else{
        rep(i,2,m){
            if(m%i)continue;
            string tmp;
            rep(j,0,m/i-1)tmp += arr[1][j];
            string tmp2;
            rep(j,1,i)tmp2 += tmp;
            //cout<<tmp2<<endl;
            if(arr[1] == tmp2){
                //multiple
                rep(j,1,n)arr[j].erase(arr[j].begin()+m/i, arr[j].end());
                m /= i;
                break;
            }
        }
        //rep(i,1,n)cout<<arr[i]<<endl;
        int ans = 100000000;
        rep(i,1,m){
            int tcnt = 0;
            rep(j,1,n)tcnt += (cnt[j])%m;
            ans = min(ans, tcnt);

            rep(j,1,n)cnt[j] = (cnt[j]+1)%m;
        }
        cout<<ans<<endl;
    }
    return 0;
}