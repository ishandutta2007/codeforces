
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 150005;
int n;
int a[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int weight = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] + 1 > weight) {
            cnt++;
            weight = max(weight + 1, a[i] - 1);
        }
    }
    cout << cnt << endl;
}