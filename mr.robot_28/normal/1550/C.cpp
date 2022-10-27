#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5;

signed main()
{
//  ios_base::sync_with_stdio(0);
//  cin.tie(0);
//  cout.tie(0);
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
        stack <pair <int, int> > st1;
        st1.push({-1e9, -1});
        st.push({1e9, -1});
        int s = 0;
        vector <int> left1(n), right1(n);
        vector <int> left2(n), right2(n);
        for(int i = 0; i < n; i++)
        {
            while(sz(st) > 0 && st.top().X < a[i])
            {
                st.pop();
            }
            left1[i] = i - st.top().Y - 1; 
            st.push({a[i], i});
            while(sz(st1) > 0 && st1.top().X > a[i])
            {
                st1.pop();
            }
            left2[i] = i - st1.top().Y - 1;
            st1.push({a[i], i});
        }
        while(sz(st) > 0)
        {
            st.pop();
        }
        while(sz(st1) > 0)
        {
            st1.pop();
        }
        st.push({1e9, n});
        st1.push({-1e9, n});
        for(int i = n - 1; i >= 0; i--)
        {
            while(sz(st) > 0 && st.top().X < a[i])
            {
                st.pop();
            }
            right1[i] = st.top().Y - i - 1;
            st.push({a[i], i});
            while(sz(st1) > 0 && st1.top().X > a[i])
            {
                st1.pop();
            }
            right2[i] = st1.top().Y - i - 1;
            st1.push({a[i], i});
        }
        vector <int> vals_up(n, 1e9);
        for(int i = 1; i < n - 1; i++)
        {
            if(i - left1[i] - 1 >= 0 && left1[i] > 0)
            {
                vals_up[i - left1[i] - 1] = min(vals_up[i - left1[i] - 1], i + right2[i]);
            }
            if(i - left2[i] - 1 >= 0 && left2[i] > 0)
            {
                vals_up[i - left2[i] - 1] = min(vals_up[i - left2[i] - 1], i + right1[i]);
            }

        }
        int right_up = n - 1;
        for(int i = n - 1; i >= 0; i--)
        {
            if(i != n - 1)
            {
                right_up = min(right_up, vals_up[i]);
                if(a[i + 1] > a[i])
                {
                    right_up = min(right_up, i + 1 + right1[i + 1]);
                }
                else if(a[i + 1] < a[i])
                {
                    right_up = min(right_up, i + 1 + right2[i + 1]);
                }
                else
                {
                    right_up = min(right_up, i + 1);
                }
            }
      //      cout << right_up << " ";
            s += right_up - i + 1;
        }
        cout << s << "\n";
    }
    return 0;
}