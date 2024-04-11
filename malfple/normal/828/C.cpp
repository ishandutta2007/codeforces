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
string str[100005];
vector<pii>vec;

queue<pii>q;

string ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n;
    rep(i,1,n){
        cin>>str[i];
        int x;
        cin>>x;
        rep(j,1,x){
            int y;
            cin>>y;
            vec.pb(mp(y,i));
        }
    }

    sort(vec.begin(), vec.end());

    int p = 0;
    int step = 1;
    pii curr = mp(-1, -1);
    while(1){
        while(p < vec.size() && vec[p].ff <= step)q.push(vec[p++]);

        while(1){
            if(curr.ff == -1 || step >= curr.ff + str[curr.ss].size()){
                if(q.empty()){
                    curr.ff = -1;
                    break;
                }
                curr = q.front();
                q.pop();
            }else break;
        }

        //printf("%d %d\n",curr.ff, curr.ss);

        if(curr.ff == -1 && p >= vec.size() && q.empty())break;

        if(curr.ff == -1)ans += 'a';
        else ans += str[curr.ss][step-curr.ff];

        step++;
    }

    cout << ans << endl;

    return 0;
}