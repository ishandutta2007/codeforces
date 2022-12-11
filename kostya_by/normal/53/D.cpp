#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int a[300], b[300], n;
vector< pair<int, int> > ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i]) continue;
        int jj = i;
        for (int j = i; j < n; j++) if (a[i] == b[j])
        {
            jj = j;
            break;
        }
        for (int j = jj - 1; j != i - 1; j--)
        {
            ans.push_back(make_pair(j, j + 1));
            swap(b[j], b[j + 1]);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
    return 0;
}