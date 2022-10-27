#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
#define int long long
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> vec;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if(a == 1)
            {
                vec.push_back(1);
            }
            else
            {
                while(1)
                {
                    if(vec.back() == a - 1)
                    {
                        vec.back() = a;
                        break;
                    }
                    vec.pop_back();
                }
            }
            for(int j = 0; j < sz(vec) - 1; j++)
            {
                cout << vec[j] << ".";
            }
            cout << vec.back() << "\n";
        }
    }
    return 0;
}