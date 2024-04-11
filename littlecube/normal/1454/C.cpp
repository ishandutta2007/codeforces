#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, _min, front, back;
        deque<int> v;
        cin >> n;
        _min = n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            if (v.empty() || tmp != v.back())
                v.emplace_back(tmp);
        }

        front = v.front();
        back = v.back();

        sort(v.begin(), v.end());

        if (!v.empty())
        {
            int l = v.front();
            for (int i = 0; i < n; i++)
            {
                int tmp = (upper_bound(v.begin(), v.end(), l) - lower_bound(v.begin(), v.end(), l));
                if (l == front)
                    tmp--;
                if (l == back)
                    tmp--;
                _min = min(tmp + 1, _min);
                if (upper_bound(v.begin(), v.end(), l) == v.end())
                    break;
                else
                    l = *upper_bound(v.begin(), v.end(), l);
            }
        }
        else
            _min = 0;
        cout << _min << '\n';
    }
}