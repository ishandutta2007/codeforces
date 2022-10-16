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

string str;
int n,q;
int prefsum[11][11][4][100005];

int update(int* arr, int x,int v){
    x++;
    repp(i,x,n+1,i&-i)arr[i] += v;
}

int query_p(int* arr,int x){
    x++;
    int ret = 0;
    revv(i,x,1,i&-i)ret += arr[i];
    return ret;
}

int query(int* arr,int l,int r){
    return query_p(arr, r) - query_p(arr, l-1);
}

inline int toint(char x){
    switch(x){
        case 'A':
            return 0;
        case 'T':
            return 1;
        case 'G':
            return 2;
        case 'C':
            return 3;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>str;
    n = str.size();

    rep(k,1,10){
        rep(i,0,n-1){
            update(prefsum[k][i%k][toint(str[i])], i/k, 1);
        }
    }

    cin>>q;
    while(q--){
        int ord,l,r;
        string tmp;
        cin>>ord;
        if(ord == 1){
            cin>>l>>tmp;
            l--;
            rep(k,1,10){
                update(prefsum[k][l%k][toint(str[l])], l/k, -1);
            }
            str[l] = tmp[0];
            rep(k,1,10){
                update(prefsum[k][l%k][toint(str[l])], l/k, 1);
            }
        }else if(ord == 2){
            cin>>l>>r>>tmp;
            l--;r--;
            int k = tmp.size();
            int ans = 0;
            rep(i,0,k-1){
                int cmp = toint(tmp[(i+k-(l%k))%k]);

                int lb = l/k;
                if(i < l%k)lb++;
                int ub = r/k;
                if(i > r%k)ub--;

                //printf("at %d lbub %d %d cmp %d\n",i,lb,ub,cmp);

                ans += query(prefsum[k][i][cmp], lb, ub);
            }
            cout << ans << endl;
        }
    }

    return 0;
}