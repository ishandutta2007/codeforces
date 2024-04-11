
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6 + 5;
int n, m;
string str[N];
int width[N];
bool reachable[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        for(int j = 0; j < m; j++) {
            if(str[i][j] == '.') {
                reachable[j] = (i == 0 && j == 0) || (i > 0 && reachable[j]) || (j > 0 && reachable[j - 1]);
                width[i + j] += reachable[j];
                if(!reachable[j]) {
                    str[i][j] = '#';
                }
            }else {
                reachable[j] = false;
                str[i][j] = '#';
            }
        }
    }
    fill(reachable, reachable + m, false);
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(str[i][j] == '.') {
                reachable[j] = (i == n - 1 && j == m - 1) || (i < n - 1 && reachable[j]) || (j < m - 1 && reachable[j + 1]);
                width[i + j] -= !reachable[j];
            }else {
                reachable[j] = false;
            }
        }
    }
    int minwidth = 2;
    for(int i = 1; i < m + n - 2; i++) {
        minwidth = min(minwidth, width[i]);
    }
    cout << minwidth << endl;
}