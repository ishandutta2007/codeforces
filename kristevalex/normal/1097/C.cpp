#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)


int a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;

    int ans2 = 0;


    cin >> n;

    vector<int> data1;
    vector<int> data2;

    for (int i = 0; i < n; i++)
        {
        string text;
        cin >> text;


        int val_ = 0;

            for (int j = 0; j < text.size(); j++)
                {
                if (text[j] == '(') ++val_;
                else --val_;

                }



        if (val_ >= 0)
            {
            int val = 0;
            for (int j = 0; j < text.size(); j++)
                {
                if (text[j] == '(') ++val;
                else --val;

                if (val < 0) break;
                }

            if (val > 0) data1.push_back(val);
            if (val == 0) ans2++;
            }
        else
            {
            int val = 0;
            for (int j = text.size()-1; j >= 0; --j)
                {
                if (text[j] == ')') ++val;
                else --val;

                if (val < 0) break;
                }

            if (val > 0) data2.push_back(val);
            if (val == 0) ans2++;
            }
        }

    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    /*for (int i = 0; i < data1.size(); i++)
        {
        cout << data1[i] << " ";
        }
    cout << endl;

    for (int i = 0; i < data2.size(); i++)
        {
        cout << data2[i] << " ";
        }
    cout << endl;*/

    int i = 0, j = 0;
    while(i < data1.size() && j < data2.size())
        {
        while (data1[i] > data2[j])
            {
            j++;
            if (i >= data1.size() || j >= data2.size()) break;
            }

        if (i >= data1.size() || j >= data2.size()) break;

        if (data1[i] == data2[j]) {++ans; ++j;}

        ++i;
        }




    cout << ans + ans2/2;

    return 0;
    }