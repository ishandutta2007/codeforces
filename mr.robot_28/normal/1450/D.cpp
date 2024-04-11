
#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        stack <pair <int, int> > st;
        vector <int> left(n), right(n);
        vector <int> lens(n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            while(st.size() > 0 && st.top().first >= a[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                left[i] = -1;
            }
            else
            {
                left[i] = st.top().second;
            }
            st.push({a[i], i});
        }
        while(st.size() > 0)
        {
            st.pop();
        }
        for(int i = n - 1; i >= 0; i--)
        {
            while(st.size() > 0 && st.top().first >= a[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                right[i] = n;
            }
            else
            {
                right[i] = st.top().second;
            }
            st.push({a[i], i});
        }
        for(int i = 0; i < n; i++)
        {
          //  cout << left[i] << " " << right[i] << "\n";
            lens[a[i]] = max(lens[a[i]], right[i] - left[i] - 1);
        }
        int max1 = 1e9;
        vector <int> ans(n + 1);
        for(int i = n; i >= 1; i--)
        {
            max1 = min(max1, lens[n - i + 1]);
            if(max1 >= i)
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = 0;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}