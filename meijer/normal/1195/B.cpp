#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

const int MX=1e3, MOD=1e9+7;
ll n, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    ll lb=0, ub=n;
    while(lb != ub) {
    	ll eaten = (lb+ub+1)/2;
    	ll putIn = n - eaten;
    	ll begCandy = putIn*(putIn+1)/2;
    	if(begCandy-k >= eaten) lb = eaten;
    	else ub = eaten-1;
    }
    cout<<lb<<endl;
}