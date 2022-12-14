#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<bool> data;

int n = 1000000, m = 1000000, tmp;

string text;

int main()
    {
    FAST;


    cin >> n;

    data.resize(n);


    for (int i = 0; i < n; i++)
        {
        cin >> m;
        cin >> text;
        data[i] = true;


        for (int j = 0; j < m/2; j++)
            {
            int delta = (int)text[m-j-1];
            //cout << delta << " ";
            int delta_= (int)text[j];
            //cout << delta_ << " ";
            delta-= delta_;

            if (delta != 0 && delta != 2 && delta != -2) data[i] = 0;
            }
        }


     for (int i = 0; i < n; i++)
         {
         cout << ((data[i])? "YES":"NO") << endl;
         }





    return 0;

    }