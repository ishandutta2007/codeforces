#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int row[8] = {0}, col[8] = {0}, r = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char c;
            cin >> c;
            if (c == 'B')
            {
                row[i]++;
                col[j]++;
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if(row[i] == 8){
            r++;
        }
    }
    for (int j = 0; j < 8; j++)
    {
        if(col[j] == 8){
            r++;
        }
    }
    if(r== 16){
        cout << 8;
    }
    else
        cout << r;
}