#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 1e5;

ll n, tot=0;
ll a[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n)cin>>a[i], tot+=a[i];
    if(tot % 2) {
        cout<<"NO"<<endl;
        return 0;
    }
    REP(i,0,n) {
        if(a[i] > tot/2) {
        cout<<"NO"<<endl;
        return 0;
        }
    }
    cout<<"YES"<<endl;
}