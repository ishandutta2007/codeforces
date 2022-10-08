
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n;
double d;
int a[MAX_N];
bool change[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> d;
        a[i] = floor(d);
        change[i] = abs(a[i] - d) > 1e-7;
        sum += a[i];
    }
    for(int j = 0; j < n && sum < 0; j++) {
        if(change[j]) {
            a[j]++;
            sum++;
        }
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}