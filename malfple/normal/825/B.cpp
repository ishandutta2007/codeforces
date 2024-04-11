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

char arr[15][15];

bool cek(){
    rep(i,1,10){
        rep(j,1,6){
            rep(k,0,4){
                if(arr[i][j+k] != 'X')break;
                if(k==4)return true;
            }
        }
    }
    rep(i,1,6){
        rep(j,1,10){
            rep(k,0,4){
                if(arr[i+k][j] != 'X')break;
                if(k==4)return true;
            }
        }
    }
    rep(i,1,6){
        rep(j,1,6){
            rep(k,0,4){
                if(arr[i+k][j+k] != 'X')break;
                if(k==4)return true;
            }
        }
    }
    rep(i,5,10){
        rep(j,1,6){
            rep(k,0,4){
                if(arr[i-k][j+k] != 'X')break;
                if(k==4)return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    rep(i,1,10){
        rep(j,1,10){
            cin>>arr[i][j];
        }
    }

    rep(i,1,10){
        rep(j,1,10){
            if(arr[i][j] == '.'){
                arr[i][j] = 'X';
                if(cek()){
                    cout << "YES" << endl;
                    return 0;
                }
                arr[i][j] = '.';
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}