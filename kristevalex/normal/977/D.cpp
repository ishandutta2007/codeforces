#include <bits/stdc++.h>
using namespace std;


long long NOD(long long x, long long y)
    {
    if (x == 0) return y;
    if (y == 0) return x;
    if (x == y) return x;
    if (x == 1 || y == 1) return 1;
    return NOD(x%y, y%x);
    }


int n;

struct mval
    {
    long long value;

    long long get_num ()
        {
        long long returned = 0, tmp, tmp_val = value;
        while((tmp = NOD(3, tmp_val)) == 3) tmp_val/= 3, returned++;
        while((tmp = NOD(2, tmp_val)) == 2) tmp_val/= 2, returned--;
        return returned;
        }

    bool operator< (mval over)
        {
        return (get_num() > over.get_num());
        }
    };


vector<mval> data;





int main()
    {
    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i].value;
        }

    sort(data.begin(), data.end());

    for (int i = 0; i < n; i++)
        {
        cout << data[i].value << " ";
        }


    return 0;
    }