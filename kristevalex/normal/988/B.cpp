#include <bits/stdc++.h>
using namespace std;



struct mstring
    {
    string value;

    mstring ()
        {}

    bool operator< (mstring over)
        {
        return value.size() < over.value.size();
        }

    bool check (mstring over)
        {
        int Size_over = over.value.size(), Size_me = value.size();

        for (int i = 0; i <= Size_over - Size_me; i++)
            {
            bool is_ok = true;
            for (int j = 0; j < Size_me; j++)
                {
                if (over.value[i+j] != value[j])
                    {
                    is_ok = false;
                    break;
                    }
                }
            if (is_ok) return true;
            }
        return false;
        }
    };


int n;



int main()
    {
    cin >> n;

    vector<mstring> data (n);

    for (int i = 0; i < n; i++)
        cin >> data[i].value;

    sort(data.begin(), data.end());


    for (int i = 0; i < n-1; i++)
        {
        if (data[i].check(data[i+1])) continue;
        cout << "NO";
        return 0;
        }

    cout << "YES" << endl;

    for (int i = 0; i < n; i++)
        {
        cout << data[i].value << endl;
        }


    return 0;
    }