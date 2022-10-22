#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 4000;

int n;
int a[MX];
map<int, int> cnt;
int needToRemove = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    REP(i,0,n) cin>>a[i];
    REP(i,0,n) cnt[a[i]] = 0;
    REP(i,0,n) cnt[a[i]]++;
    for(auto a : cnt)
        needToRemove += a.second-1;
    if(needToRemove == 0) {
        cout<<0<<endl;
        return 0;
    }

    int best = n-1;
    int e = 0;
    REP(b,0,n) {
        while(needToRemove != 0) {
            if(e == n) break;
            cnt[a[e]]--;
            if(cnt[a[e]] != 0)
                needToRemove--;
            e++;
            if(e == n) break;
        }
        if(needToRemove != 0) break;
        best = min(best, e-b);
        cnt[a[b]]++;
        if(cnt[a[b]] != 1) needToRemove++;
    }
    cout<<best<<endl;
}