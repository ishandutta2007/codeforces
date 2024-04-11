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

int id = 0;

string getlastname(){
    string ret;
    int tmp = id;
    ret += tmp%26 + 'A';
    tmp /= 26;
    while(tmp){
        ret += tmp%26 + 'a';
        tmp /= 26;
    }
    return ret;
}

string getnewname(){
    id++;
    return getlastname();
}

string arr[55];

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;

    arr[1] = getlastname();
    int stage = 1;
    rep(i,1,n-m+1){
        string in;
        cin>>in;
        if(i == n-m+1 && stage == 1)stage = 3;
        if(in[0] == 'Y'){
            if(stage == 1){
                rep(j,i+1,i+m-1){
                    arr[j] = getnewname();
                }
                stage = 2;
            }else if(stage == 2){
                arr[i+m-1] = getnewname();
            }else if(stage == 3){
                rep(j,i+1,i+m-1){
                    arr[j] = getnewname();
                }
            }
        }else if(in[0] == 'N'){
            if(stage == 1){
                arr[i+1] = getlastname();
            }else if(stage == 2){
                arr[i+m-1] = arr[i];
            }else if(stage == 3){
                rep(j,i+1,i+m-1){
                    arr[j] = getlastname();
                }
            }
        }else return -1;
    }

    rep(i,1,n){
        cout << arr[i];
        if(i == n)cout << endl;
        else cout << " ";
    }
    return 0;
}