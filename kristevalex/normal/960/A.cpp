#include <bits/stdc++.h>
using namespace std;

                      //aaaabbcccc
string text;

int main()
    {
    cin >> text;

    int n = text.size();

    int i = 0;


    while (text[i] == 'a') i++;

    if (i == 0)
        {
        //cout << 0;

        cout << "NO";
        return 0;

        }

    //cout << 0;

    int j = i;

    while (text[j] == 'b' && j < n) j++;

    if (i == j)
        {
        cout << "NO";
        return 0;

        }

    for (int tmp = j; tmp < n; tmp++)
        {
        //cout << tmp << endl;
        if (text[tmp] != 'c')
            {
            cout << "NO";
            return 0;

            }
        }
    //cout << i << " " << j << " " << n << endl;


    if (n - j == i ||
        n - j == j - i)
        {
        cout << "YES";
        return 0;
        }

    cout << "NO";
    return 0;


    }