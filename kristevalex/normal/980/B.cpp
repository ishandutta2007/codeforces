#include <bits/stdc++.h>
using namespace std;




int n, k;



vector<int> sequence;



int main()
    {
    cin >> n >> k;


    if (k > 2*(n-2))
        {
        cout << "NO" << endl;
        return 0;
        }

    cout << "YES" << endl;

    if (k == 1)
        {
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            {
            if ((n+1)/2 != i+1) cout << ".";
            else cout << "#";
            }
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
        return 0;
        }

    if (k == 3)
        {
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            {
            if ((n+1)/2 - 1 > i+1 || (n+1)/2 + 1 < i+1) cout << ".";
            else cout << "#";
            }
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
        return 0;
        }

    if ((k/2)*2 == k)
        {
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            {
            if (i == 0 || i > k/2) cout << ".";
            else cout << "#";
            }
        cout << endl;

        for (int i = 0; i < n; i++)
            {
            if (i == 0 || i > k/2) cout << ".";
            else cout << "#";
            }
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
        return 0;
        }

    if ((k/2)*2 != k)
        {
        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;

        for (int i = 0; i < n; i++)
            {
            if (i == 0 || i == 2 || i > (k+1)/2) cout << ".";
            else cout << "#";
            }
        cout << endl;

        for (int i = 0; i < n; i++)
            {
            if (i == 0 || i > (k+1)/2) cout << ".";
            else cout << "#";
            }
        cout << endl;

        for (int i = 0; i < n; i++)
            cout << ".";
        cout << endl;
        return 0;
        }


    return 0;
    }