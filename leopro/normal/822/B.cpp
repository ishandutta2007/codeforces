#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<string.h>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int min = 10000;
    int count;
    for (int i = 0; i <= m - n; ++i) {
        count = 0;
        for (int j = i; j < i + n; ++j) {
            if (s[j - i] != t[j]) count++;
        }
        if (count < min) min = count;
    }
    for (int i = 0; i <= m - n; ++i) {
        count = 0;
        for (int j = i; j < i + n; ++j) {
            if (s[j - i] != t[j]) count++;
        }
        if (count == min) {
            cout << min << endl;
            for (int j = i; j < i + n; ++j) {
                if (s[j - i] != t[j]) cout << j - i + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    return 0;
}