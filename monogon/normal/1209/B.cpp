
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n;
int a[N], b[N];
string str;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> str;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    int M = 0;
    for(int i = 0; i < 1000; i++) {
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            cnt += (str[j] == '1');
            if(i >= b[j] && (i - b[j]) % a[j] == 0) {
                str[j] = (str[j] == '0' ? '1' : '0');
            }
        }
        M = max(M, cnt);
    }
    cout << M << endl;
}