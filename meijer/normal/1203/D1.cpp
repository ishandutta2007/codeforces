#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)

const int MX = 2e5+1e4;

string a, b;
int n, m;
int mxB[MX], mxE[MX];

bool possible(int c) {
    REP(i,0,n-c+1) {
        if(mxB[i]+mxE[i+c] >= m)
            return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>a>>b; n=a.size(), m=b.size();
    int j=0;
    REP(i,0,n) {
        mxB[i] = j;
        if(j!=m && a[i] == b[j]) j++;
    } mxB[n] = j;
    j=0;
    REP(k,0,n) {
        int i=n-k-1;
        mxE[i+1] = j;
        if(j!=m && a[i] == b[m-j-1]) j++;
    } mxE[0] = j;

    int lb=0, ub=n-1;
    while(lb != ub) {
        int c=(lb+ub)/2; c++;
        if(possible(c)) lb = c;
        else            ub = c-1;
    }
    cout<<lb<<endl;
}