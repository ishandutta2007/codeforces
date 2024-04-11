#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N = 1e6 + 100;
const int M =  2e5;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector <int> vec;
        for(int i = 0; i < n; i++)
        {
            vec.push_back(s[i] - 'a');
        }
        sort(vec.begin(), vec.end());
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int k = s[i] - 'a';
            if(k != vec[i])
            {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}