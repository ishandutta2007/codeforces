#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 301;

vector <pair <int, int> > ans;
int n, a[Maxn], b[Maxn];

int main()
{
    int i, j;
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    for (i = 1; i <= n; i++) cin >> b[i];
    for (i = 1; i <= n; i++) {
        for (j = i; a[i] != b[j]; j++) ;
        while (j > i) {
              ans.push_back(make_pair(j-1, j));
              swap(b[j-1], b[j]);
              j--;
        }
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
       cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}