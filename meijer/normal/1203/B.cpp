#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX=10000;

int q, n;
int a[MX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>q;
    while(q--) {
        cin>>n; n*=4;
        map<int, int> cnt;
        int big=0, small=INF, area;
        REP(i,0,n) cin>>a[i], cnt[a[i]] = 0, big=max(big, a[i]), small=min(small, a[i]);
        REP(i,0,n) cnt[a[i]]++;
        area = big*small;
        bool pos=1;
        for(auto a : cnt) {
            if(a.second % 2) pos=0;
            if(area % a.first) pos=0;
            int other = area/a.first;
            if(cnt[other] != a.second) pos=0;
        }
        cout<<(pos?"YES":"NO")<<endl;
    }
}