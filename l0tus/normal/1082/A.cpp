#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int INF = 2e9;
const int mx = 1e5;

struct C{
    int a,b;
    C(){};
    C(int a,int b):a(a),b(b){};
    bool operator < (const C &X) const{
        return a<X.a;
    }
};

int N,M,S,A[mx],B[mx],ans,cnt;
vector<int> V;
queue<int> Q;
stack<int> s;
priority_queue<int> PQ;
int t,n,x,y,d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> n >> x >> y >> d;
        int m = abs(x-y);
        ans = INF;
        if(m%d==0) ans = min(ans,(m+d-1)/d);
        if((y-1)%d==0) ans = min(ans,(y+d-2)/d+(x+d-2)/d);
        if((n-y)%d==0) ans = min(ans,(n+d-y-1)/d+(n-x+d-1)/d);
        if(ans == INF) cout << -1 << '\n';
        else cout << ans << '\n';
    }
}