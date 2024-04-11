#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=16383;
const int N=7;
int ans1, ans2, ans;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"?";
    REP(i,1,101) cout<<" "<<i;
    cout<<endl;
    fflush(stdout);
    cin>>ans1;
    cout<<"?";
    REP(i,1,101) cout<<" "<<(i<<N);
    cout<<endl;
    fflush(stdout);
    cin>>ans2;
    ans = 0;
    REP(i,0,N)
        ans |= ans1&(1<<(i+N));
    REP(i,0,N)
        ans |= ans2&(1<<(i));
    cout<<"! "<<ans<<endl;
}