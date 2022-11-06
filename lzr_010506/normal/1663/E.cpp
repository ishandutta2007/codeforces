//
// Created by onglu on 2022/3/14.
//

#include <bits/stdc++.h>
using namespace std;

string a[110];
string b = "theseus";
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    int flag = 0;

    for(int i = 1; i <= n; i ++)
        for(int j = 0; j < a[i].size(); j ++)
        {
            int x = i, y = j;
            for(int k = 0; k < 7; k ++)
            {
                if(a[x][y] != b[k]) break;
                if(k == 6) flag = 1;
                y ++;
            }
            x = i, y = j;
            for(int k = 0; k < 7; k ++)
            {
                if(a[x][y] != b[k]) break;
                if(k == 6) flag = 1;
                x ++;
            }
            x = i, y = j;
            for(int k = 0; k < 7; k ++)
            {
                if(a[x][y] != b[k]) break;
                if(k == 6) flag = 1;
                x ++;
                y ++;
            }
        }
    if(flag == 1) cout << "YES";
    else cout << "NO";
}