#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 0;
    int k = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < k) continue;
        cnt++;
        k++;

    }
    cout << cnt << endl;
    return 0;
}