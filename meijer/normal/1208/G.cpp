#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=1e6+1e5;

int n, k;
ll euler[MX];

void construct(int mx) {
    iota(euler, euler+mx+1, 0);
    REP(i,2,mx+1) {
        if(euler[i] == i) {
            euler[i]--;
            for(ll j=i*2; j<=mx; j+=i) {
                euler[j]=(euler[j]/i)*(i-1);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    if(k == 1) {cout<<3<<endl; return 0;}
    construct(n);
    sort(euler+1,euler+n+1);
    cout<<accumulate(euler+1,euler+k+3,ll(0))<<endl;
}