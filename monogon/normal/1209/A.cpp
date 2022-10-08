
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int cnt = n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(a[i] % a[j] == 0) {
                cnt--;
                goto endloop;
            }
        }
        endloop:;
    }
    cout << cnt << endl;
}