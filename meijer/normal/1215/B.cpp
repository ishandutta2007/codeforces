#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define INF 1e9

const int MX=3e5;
int n;
int a[MX];
ll memNeg[MX];
ll memPos[MX];

ll getNeg(int i);
ll getPos(int i) {
    if(i == n) return 0;
    if(memPos[i] == -1) {
        if(a[i]<0) {
            memPos[i] = getNeg(i+1);
        } else {
            memPos[i] = getPos(i+1)+1;
        }
    }
    return memPos[i];
}
ll getNeg(int i) {
    if(i == n) return 0;
    if(memNeg[i] == -1) {
        if(a[i]<0) {
            memNeg[i] = getPos(i+1)+1;
        } else {
            memNeg[i] = getNeg(i+1);
        }
    }
    return memNeg[i];
}

int main() {
    cin>>n;
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) memNeg[i]=memPos[i]=-1;
    ll ans1=0, ans2=0;
    REP(i,0,n)
        ans1 += getNeg(i), ans2 += getPos(i);
    cout<<ans1<<" "<<ans2<<endl;
}