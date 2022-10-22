#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=1e3;
int n;
ll M[MX][MX];

int root(ll a) {
    ll lb=0, ub=a;
    while(lb != ub) {
        ll mid = (lb+ub+1)/2;
        if(mid*mid > a) ub = mid-1;
        else lb = mid;
    }
    return lb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n)
        REP(j,0,n)
            cin>>M[i][j];
    ll bS = (M[0][1]*M[1][2])/M[0][2];
    ll b = root(bS);
    REP(i,0,n) {
        if(i != 0) cout<<" ";
        if(i == 1) cout<<b;
        else {
            cout<<M[i][1]/b;
        }
    }
    cout<<endl;
}