#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n;
string row[N];

int main() {

    cin >> n;
    bool found = false;
    for (int i = 1; i <= n; i++) {
        cin >> row[i];
        if (!found && row[i][0] == 'O' && row[i][1] == 'O') {
            found = true;
            row[i][0] = row[i][1] = '+';
        }
        if (!found && row[i][3] == 'O' && row[i][4] == 'O') {
            found = true;
            row[i][3] = row[i][4] = '+';
        }
    }

    if (!found) {
        printf("NO\n");
        return 0;
    }

    printf("YES\n");
    for (int i = 1; i <= n; i++) {
        cout << row[i] << endl;
    }

    return 0;
}