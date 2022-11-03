#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int a[4][4];
pair<int , int> p[20];
int n;
bool check(int x , int y)
{
    pair<int , int> k[20];
    for(int i = 0; i < n; i++)
    {
        k[i].first = p[i].first + x;
        k[i].second = p[i].second + y;
        if(k[i].first >= 4 || k[i].first < 0)
            return 0;
        if(k[i].second >= 3 || k[i].second < 0)
            return 0;
        if(k[i].first == 3 && k[i].second != 1)
                return 0;
    }
    return 1;
}
int main()
{
    a[0][0] = 1;
    a[0][1] = 2;
    a[0][2] = 3;
    a[1][0] = 4;
    a[1][1] = 5;
    a[1][2] = 6;
    a[2][0] = 7;
    a[2][1] = 8;
    a[2][2] = 9;
    a[3][0] = -1;
    a[3][2] = -1;
    string s;
    cin >> n >> s;
    for(int i = 0; i < n; i++)
    {
        bool f = 0;
        for(int j = 0; j < 4 && !f; j++)
            for(int z = 0; z < 3 && !f; z++)
                if(s[i] - '0' == a[j][z])
                    p[i].first = j , p[i].second = z , f = 1;
    }
    for(int i = -20; i <= 20; i++)
        for(int j = -20; j <= 20; j++)
        {
            if(!i && !j)
                continue;
            if(check(i , j))
            {
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
}