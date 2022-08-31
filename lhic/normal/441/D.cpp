#include <iostream>
#include <vector>

using namespace std;


vector<int>  ans;

int a[4000];

int col[4000];

void DFS(int x, int now)
{
    if (col[x])
        return;
    col[x] = now;
    DFS(a[x], now);
}

int n,m;


int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        --a[i];
    }
    cin >> m;
    int now = 1;

    for (int i = 0; i < n; ++i)
    {
        if (!col[i])
        {
            DFS(i,now);
            ++now;
        }
    }
    --now;
    //cout << n - now << "\n";
    while (n - now < m)
    {
        for (int i = 0; i < n; ++i)
            if (col[i] != 1)
            {
                ans.push_back(1);
                ans.push_back(i+1);
                for (int j = i + 1; j < n; ++j)
                {
                    if (col[j] == col[i])
                        col[j] = 1;
                }
                col[i] = 1;
                --now;
                break;
            }
    }

    while (n - now > m)
    {
        for (int i = 0; i < n; ++i)
            if (a[i] != i)
            {
                for (int j = i + 1; j < n; ++j)
                {
                    if (col[i] == col[j])
                    {
                        ++now;
                        int nn = i;
                        while (nn != j)
                        {
                            col[nn] = now;
                            nn = a[nn];
                        }
                        swap(a[i], a[j]);
                        swap(col[i], col[j]);
                        ans.push_back(i + 1);
                        ans.push_back(j + 1);
                        break;
                    }
                }
                break;
            }
    }
    cout << ans.size() / 2 << "\n";
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] << " ";


    return 0;
}