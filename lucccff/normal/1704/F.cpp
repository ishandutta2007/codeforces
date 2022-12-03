#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, x;
char ch[N];
int pre[N];
int sg[N][20];
vector <int> num[20];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    pre[0] = 0;
    pre[1] = 0;
    num[0].push_back(0);
    num[0].push_back(1);
    sg[2][0] = 1;
    sg[3][0] = 1;
    sg[4][0] = 1;
    for(int i = 2; i < N - 5; i++) {
        int j = 0;
        while(sg[i][j]) j++;
        pre[i] = j;
        num[j].push_back(i);
        for(int k = 0; k < 16; k++) {
            int x = j ^ k;
            for(int j = 0; j < 100 && j < num[k].size() && num[k][j] + i < N - 2; j++) {
                sg[num[k][j] + i + 2][x] = 1;
            }
        }
    }
    while (t--) {
        cin >> n;
        cin >> ch;
        int cnt = 0;
        int r1 = 0, b1 = 0;
        for(int i = 0; i < n; i++) {
            if (ch[i] == 'R') r1++;
            else b1++;
        }
        int x = 0;
        for(int i = 1; i < n; i++) {
            int k = i;
            while(k < n && ch[k] != ch[k - 1]) {
                k++;
            }
            x ^= pre[k - i + 1];
            i = k;
        }
        if (x == 0) {
            if (b1 >= r1) {
                cout << "Bob\n";
                continue;
            }
            else {
                cout << "Alice\n";
                continue;
            }
        }
        else {
            if (b1 > r1) {
                cout << "Bob\n";
                continue;
            }
            else {
                cout << "Alice\n";
                continue;
            }
        }
    }
    return 0;
}