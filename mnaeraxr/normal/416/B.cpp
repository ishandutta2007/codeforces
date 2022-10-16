//#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    int *p = new int[m*n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i*n + j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value = i*n + j;
            if (i == 0)
            {
                if (j == 0)
                {
                    continue;
                }
                p[value] += p[value - 1];
            }
            else
            {
                if (j == 0)
                {
                    p[value] += p[value - n];
                }
                else
                {
                    if (p[value - 1] > p[value - n])
                    {
                        p[value] += p[value - 1];
                    }
                    else
                    {
                        p[value] += p[value - n];
                    }
                }
            }
        }
        if (i == 0)
        {
            cout << p[(i + 1)*n - 1];
        }
        else
        {
            cout << " " << p[(i + 1)*n - 1];
        }
    }
    cout << "\n";
}