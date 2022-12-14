#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)


struct XY
    {
    int x, y;
    };


//long long n, m, k, ans;


int main()
    {
    FAST;

    int X_MIN, X_MAX, Y_MIN, Y_MAX;


    vector<XY> data1 (4);
    vector<XY> data2 (4);


    for (int i = 0; i < 4; i++)
        {
        cin >> data1[i].x >> data1[i].y;
        }

    for (int i = 0; i < 4; i++)
        {
        cin >> data2[i].x >> data2[i].y;
        }


    X_MIN = min(data1[0].x, data1[2].x);
    X_MAX = max(data1[0].x, data1[2].x);
    Y_MIN = min(data1[0].y, data1[2].y);
    Y_MAX = max(data1[0].y, data1[2].y);
    for (int i = 0; i < 4; i++)
        {
        if (data2[i].x >= X_MIN && data2[i].x <= X_MAX)
            if ((data2[i].y >= Y_MIN && data2[i].y <= Y_MAX))
                {
                cout << "YES";
                return 0;
                }
        }

    int tmpx, tmpy;

    for (int i = 0; i < 4; i++)
        {
        tmpx = data1[i].x;
        tmpy = data1[i].y;
        data1[i].x = tmpx-tmpy;
        data1[i].y = tmpx+tmpy;
        }

    for (int i = 0; i < 4; i++)
        {
        tmpx = data2[i].x;
        tmpy = data2[i].y;
        data2[i].x = tmpx-tmpy;
        data2[i].y = tmpx+tmpy;
        }



    X_MIN = min(data2[0].x, data2[2].x);
    X_MAX = max(data2[0].x, data2[2].x);
    Y_MIN = min(data2[0].y, data2[2].y);
    Y_MAX = max(data2[0].y, data2[2].y);
    for (int i = 0; i < 4; i++)
        {
        if (data1[i].x >= X_MIN && data1[i].x <= X_MAX)
            if ((data1[i].y >= Y_MIN && data1[i].y <= Y_MAX))
                {
                cout << "YES";
                return 0;
                }
        }

    int x_mid = (data1[0].x+data1[2].x)/2;
    int y_mid = (data1[0].y+data1[2].y)/2;

    if (x_mid >= X_MIN && x_mid <= X_MAX &&
        y_mid >= Y_MIN && y_mid <= Y_MAX)
        {
        cout << "YES";
        return 0;
        }


    cout << "NO";

    return 0;
    }