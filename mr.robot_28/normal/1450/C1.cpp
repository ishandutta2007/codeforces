
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
        int n, m;
        cin >> n;
        m = n;
        int k = 0;
        vector <vector <char> > a(n, vector <char> (m));
        for(int i = 0; i< n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if(a[i][j] == 'X')
                {
                    k++;
                }
            }
        }
        vector <int> p;
        for(int i =0; i < 3; i++)
        {
            p.push_back(i + 1);
        }
        do{
            int cnt1 = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if((j + p[i % 3]) % 3 == 0)
                    {
                        if(a[i][j] == 'X')
                        {
                            cnt1++;
                        }
                    }
                }
            }
            if(cnt1 * 3 <= k)
            {
                for(int i = 0; i < n; i++)
                {
                    for(int j = 0; j < n; j++)
                    {
                        if((j + p[i % 3]) % 3 == 0)
                        {
                            if(a[i][j] == '.')
                            {
                                cout << '.';
                            }
                            else
                            {
                                cout << "O";
                            }
                        }
                        else
                        {
                            cout << a[i][j];
                        }
                    }
                    cout << "\n";
                }
                break;
            }
        }while(next_permutation(p.begin(), p.end()));
    }
    return 0;
}