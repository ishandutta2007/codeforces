#include <iostream>
#include <set>

using namespace std;

struct Element {
    int value, color;
};

int main() {
    int n, k;
    cin >> n >> k;
    Element a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i].value;
    }
    int numbers[5001];
    for (int i = 0; i < 5001; ++i) {
        numbers[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        numbers[a[i].value]++;
    }
    int cnt = 0;
    for (int i = 0; i < 5001; ++i) {
        if (numbers[i] > cnt) { cnt = numbers[i]; }
    }
    if (cnt > k) {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
    set<int> colors[k];
    for (int i = 0; i < k; ++i) {
        colors[i].clear();
    }
    int p = 0;
    for (int i = 0; i < n; ++i) {
        bool first = true;
        int j;
        for (j = p; j != p || first; j = (j + 1) % k) {
            first = false;
            if (colors[j].find(a[i].value) == colors[j].end()) {
                colors[j].insert(a[i].value);
                a[i].color = j;
                break;
            }
        }
        p = (j + 1) % k;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i].color + 1 << " ";
    }
    cout << "\n";


    return 0;
}