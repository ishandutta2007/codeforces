#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


long long a, b, k, n, m, tmp, ans = 0;

char letter;
string text;


int main()
    {
    FAST;


    cin >> n >> m;

    vector<vector<bool>> data  (n, vector<bool> (m, false));
    vector<vector<bool>> data_ (n, vector<bool> (m, false));



    for (int i = 0; i < n; i++)
        {
        cin >> text;
        for (int j = 0; j < m; j++)
            {
            if (text[j] == '.') data[i][j] = false;
            else {data[i][j] = true; /*cout << i << " " << j << endl;*/}
            }
        }

     for (int i = 1; i < n-1; i++)
        for (int j = 1; j < m-1; j++)
            {
            //cout << i << "   " << j << endl;

            if (data[i-1][j  ] == true &&
                data[i-1][j-1] == true &&
                data[i  ][j-1] == true &&
                data[i+1][j-1] == true &&
                data[i+1][j  ] == true &&
                data[i+1][j+1] == true &&
                data[i  ][j+1] == true &&
                data[i-1][j+1] == true)
                {
                data_[i-1][j  ] = true;
                data_[i-1][j-1] = true;
                data_[i  ][j-1] = true;
                data_[i+1][j-1] = true;
                data_[i+1][j  ] = true;
                data_[i+1][j+1] = true;
                data_[i  ][j+1] = true;
                data_[i-1][j+1] = true;

                /*cout << i-1 << " " << j << endl;
                cout << i-1 << " " << j-1 << endl;
                cout << i   << " " << j-1  << endl;
                cout << i+1 << " " << j-1  << endl;
                cout << i+1 << " " << j    << endl;
                cout << i+1 << " " << j+1 << endl;
                cout << i   << " " << j+1  << endl;
                cout << i-1 << " " << j+1  << endl;  */
                }

            }



    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            {
            if (data[i][j] != data_[i][j])
            {
                cout << "No";
                return 0;
            }
            }


    cout << "Yes";

    return 0;
    }