#include <iostream>
using namespace std;

const int MAXN = 1000005;

int n, k;
int keep[MAXN];

int main() {
    cin >> n >> k;
    if (k*3>n) {
        cout << -1 << endl;
        return 0;
    }
    if (k%2==0) {
        for (int i=1; i<=k; i+=2) {
            keep[3*i-2]=i;
            keep[3*i-1]=i+1;
            keep[3*i]=i+1;
            keep[3*i+1]=i;
            keep[3*i+2]=i;
            keep[3*i+3]=i+1;
        }
    }
    else {
        keep[2]=1; keep[3]=1; keep[3*k-2]=1;
        for (int i=2; i<=k; i+=2) {
            keep[3*i-5]=i;
            keep[3*i-2]=i;
            keep[3*i-1]=i;
            keep[3*i]=i+1;
            keep[3*i+2]=i+1;
            keep[3*i+3]=i+1;
        }
    }
    for (int i=3*k+1; i<=n; i++) keep[i]=1;
    for (int i=1; i<=n; i++) {
        cout << keep[i];
        if (i<n) cout << ' ';
        else cout << endl;
    }
}