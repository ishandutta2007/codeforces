#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 1e6+1e4;

string ans, W;
int n, m;
int b[MX];

void pre() {
    int i=0, j=-1; b[0]=-1;
    while(i < m) {
        while(j>=0 && W[i] != W[j]) j=b[j];
        i++; j++;
        b[i] = j;
    }
}
int getLen() {
    int i=max(0,(int)ans.size()-m), j=0;
    while(i < ans.size()) {
        while(j>=0 && ans[i] != W[j]) j=b[j];
        i++; j++;
    }
    return j;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ans.reserve(MX);
    cin>>n;
    while(n--) {
        cin>>W; m=W.size();
        pre();
        int l = getLen();
        ans += W.substr(l, W.size()-l);
    }
    cout<<ans<<endl;
}