#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=160000;
int n;
int a[MX+1];
int cnt[MX+1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>a[i];
    REP(i,0,MX) cnt[i] = 0;
    REP(i,0,n)  cnt[a[i]]++;

    int ans=0;
    REP(i,1,MX) {
        if(cnt[i-1] != 0) {
            cnt[i-1]--;
            ans++;
        } else
        if(cnt[i] != 0) {
            cnt[i]--;
            ans++;
        } else if(cnt[i+1] != 0) {
            cnt[i+1]--;
            ans++;
        }
    }
    cout<<ans<<endl;
}