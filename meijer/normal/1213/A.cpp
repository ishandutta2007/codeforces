#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    int ans=0;
    int a;
    REP(i,0,n) {cin>>a; if(a%2) ans++;}
    ans = min(ans, n-ans);
    cout<<ans<<endl;
}