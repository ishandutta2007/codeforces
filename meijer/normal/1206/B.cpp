#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    bool hasZero=false;
    bool neg=false;
    ll cnt=0;
    REP(i,0,n) {
        int a;
        cin>>a;
        if(a == 0) hasZero = 1, cnt++;
        else cnt += max(a-1, -a-1);
        if(a<0) neg=!neg;
    }
    if(neg && !hasZero) cnt+=2;
    cout<<cnt<<endl;
}