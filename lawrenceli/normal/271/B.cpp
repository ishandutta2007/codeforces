#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXP = 100005;
const int MAXN = 505;

int n, m, minx=(int)1e9;
int mat[MAXN][MAXN];
bool isprime[MAXP];
int nextprime[MAXP];

void precompute() {
    isprime[0]=isprime[1]=false;
    for (int i=2; i<MAXP; i++) isprime[i]=true;
    for (int i=2; i<MAXP; i++) {
        if (isprime[i]) {
            for (int j=2*i; j<MAXP; j+=i) isprime[j]=false;
        }
    }
    for (int i=0; i<MAXP-1;) {
        int j;
        for (j=i; j<MAXP-1 && !isprime[j]; j++);
        for (; i<=j; i++) nextprime[i]=j;
    }
}

int main() {
    //freopen("271B.in", "r", stdin);
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
        }
    }
    precompute();
    for (int i=0; i<n; i++) {
        int x=0;
        for (int j=0; j<m; j++) x+=nextprime[mat[i][j]]-mat[i][j];
        minx=min(minx, x);
    }
    for (int i=0; i<m; i++) {
        int x=0;
        for (int j=0; j<n; j++) x+=nextprime[mat[j][i]]-mat[j][i];
        minx=min(minx, x);
    }
    cout << minx << endl;
}