#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n];
    for(int i = 0; i < n; ++i)
            cin >> t[i];
    sort(t, t + n);
    int mid = 350, total = mid + 360;
    int sum = 0, pen = 0, k = 0;
    for(int i = 0; i < n && sum + t[i] <= mid; ++i) {
            sum += t[i];
            ++k;
    }
    for(int i = k; i < n && sum + t[i] <= total; ++i) {
            sum += t[i];
            ++k;
            pen += sum - mid;
    }
    cout << k << " " << pen << endl;
    cin >> n;
    return 0;
}