#include <iostream>
using namespace std;

int n;
int a[105];
int best;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            int x=0;
            for (int k=0; k<n; k++) {
                if (k>=i && k<=j) x+=(a[k]^1);
                else x+=a[k];
            }
            best=max(best, x);
        }
    }
    cout << best << endl;
}