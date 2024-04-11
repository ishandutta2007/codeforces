#include <iostream>
#include <queue>
using namespace std;

int i, a[200005], n, ans[200005], cur;

class compare
{
public:
    bool operator () (int a, int b)
    {
        return ans[a] > ans[b];
    }
};
priority_queue <int, vector <int>, compare> heap;

int main()
{
    ios_base::sync_with_stdio();
    cin >> n;
    fill(ans + 1, ans + n + 1, -1);
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            ans[i] = 0;
            heap.push(i);
        }
    }
    while (!heap.empty())
    {
        cur = heap.top();
        if (ans[cur - 1] == -1 && cur > 1)
        {
            ans[cur - 1] = ans[cur] + 1;
            heap.push(cur - 1);

        }
        if (ans[cur + 1] == -1 && cur < n)
        {
            ans[cur + 1] = ans[cur] + 1;
            heap.push(cur + 1);
        }
        heap.pop();
    }
    for (i = 1; i <= n; i++)
        cout << ans[i] << " ";
}