
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 105;
int n, alice;
int a;
int idx[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> alice;
    int sum = alice;
    int sumalice = alice;
    int j = 0;
    idx[0] = 1;
    for(int i = 0; i < n - 1; i++) {
        cin >> a;
        sum += a;
        if(alice >= 2 * a) {
            j++;
            idx[j] = i + 2;
            sumalice += a;
        }
    }
    if(sumalice * 2 > sum) {
        cout << (j + 1) << endl;
        for(int i = 0; i <= j; i++) {
            cout << idx[i] << " ";
        }
        cout << endl;
    }else {
        cout << 0 << endl;
    }
}