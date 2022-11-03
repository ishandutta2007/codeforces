#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s[5];
bool checkc(int i , int j)
{
    int dot = 0;
    for(int dx = 0; dx < 3; dx++)
    {
        if(i + dx >= 4)
            return 0;
        if(s[i + dx][j] == 'o')
            return 0;
        if(s[i + dx][j] == '.')
            dot++;
    }
    if(dot == 1)
        return 1;
    return 0;
}
bool checkr(int i , int j)
{
    int dot = 0;
    for(int dx = 0; dx < 3; dx++)
    {
        if(j + dx >= 4)
            return 0;
        if(s[i][j + dx] == 'o')
            return 0;
        if(s[i][j + dx] == '.')
            dot++;
    }
    if(dot == 1)
        return 1;
    return 0;
}
bool checkh(int i , int j)
{
    int dot = 0;
    for(int dx = 0; dx < 3; dx++)
    {
        if(j + dx >= 4 || i + dx >= 4)
            return 0;
        if(s[i + dx][j + dx] == 'o')
            return 0;
        if(s[i + dx][j + dx] == '.')
            dot++;
    }
    if(dot == 1)
        return 1;
    return 0;
}
bool checkhh(int i , int j)
{
    int dot = 0;
    for(int dx = 0; dx < 3; dx++)
    {
        if(j - dx <= -1 || i + dx >= 4)
            return 0;
        if(s[i + dx][j - dx] == 'o')
            return 0;
        if(s[i + dx][j - dx] == '.')
            dot++;
    }
    if(dot == 1)
        return 1;
    return 0;
}
int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
    {
        if(checkr(i , j) || checkc(i , j) || checkh(i , j) || checkhh(i , j))
        {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}