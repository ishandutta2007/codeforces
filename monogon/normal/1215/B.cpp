
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n;
int a[N], z, o;
ll pos, neg;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = (a[i] > 0 ? 1 : -1);
    }
    z = o = 0;
    pos = neg = 0;
    for(int i = 0; i < n; i++) {
        z++;
        if(a[i] == 1) {
            pos += z;
            neg += o;
        }else {
            pos += o;
            neg += z;
            swap(o, z);
        }
    }
    cout << neg << " " << pos << endl;
}