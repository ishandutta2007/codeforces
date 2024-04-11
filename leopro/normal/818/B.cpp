#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>

using namespace std;

typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1], l[m];
    for (int i = 0; i < m; ++i) {
        cin >> l[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = -1;
    }
    for (int i = 0; i < m - 1; ++i) {
        int j = l[i + 1] - l[i];
        if (j <= 0) j += n;
        if (a[l[i]] != -1 && a[l[i]] != j) {
            cout << "-1\n";
            return 0;
        }
        a[l[i]] = j;
    }
    int numbers[n + 1];
    for (int i = 1; i <= n; ++i) {
        numbers[i] = false;
    }
    for (int i = 1; i <= n; ++i) {
        numbers[a[i]]++;
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (numbers[i] > 1) count++;
    }
    if (count != 0){
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            for (int j = 1; j <= n; ++j) {
                if (numbers[j] == 0) {
                    a[i] = j;
                    numbers[j] = 1;
                    break;
                }
            }

        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}