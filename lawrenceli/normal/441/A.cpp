#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, v;
vector<int> ar[55];

int main() {
    cin >> n >> v;
    vector<int> ans;
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        ar[i].resize(k);
        for (int j=0; j<k; j++) cin >> ar[i][j];
        if (v > *min_element(ar[i].begin(), ar[i].end()))
            ans.push_back(i+1);
    }
    cout << ans.size() << '\n';
    for (int i=0; i<ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}