#include <bits/stdc++.h>
using namespace std;

struct XY
    {
    long x, y, ind;

    bool operator >= (XY over)
        {
        if (x != over.x) return (x >= over.x);
        return (y <= over.y);
        }

    bool operator > (XY over)
        {
        if (x != over.x) return (x > over.x);
        return (y < over.y);
        }

    bool operator <= (XY over)
        {
        if (x != over.x) return (x <= over.x);
        return (y >= over.y);
        }

    bool operator < (XY over)
        {
        if (x != over.x) return (x < over.x);
        return (y > over.y);
        }
    };

int n;

vector<XY> data;


int main()
{
    cin >> n;

    data.resize(n);                                    //

    for (size_t i = 0; i < n; i++)
        {
        cin >> data[i].x >> data[i].y;
        data[i].ind = i+1;
        }

    sort(data.begin(), data.end());

    for (size_t i = 0; i < n-1; i++)
        {
        if (data[i].y >= data[i+1].y)
            {
            cout << data[i+1].ind << " " << data[i].ind;
            return 0;
            }
        }

    cout << "-1 -1";


    return 0;
}