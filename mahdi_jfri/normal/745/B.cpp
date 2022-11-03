#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s[510];
bool x;
int res , a , b;
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < m; j++)
            if(s[i][j] == 'X')
                res++;
    }
    for(int i = 0; i < n && !x; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(s[i][j] == 'X')
            {
                x = 1;
                a = i;
                b = j;
                break;
            }
        }
    }
    int j = b;
    while(j < m && s[a][j] == 'X')
        j++;
    int i = a;
    while(i < n && x)
    {
        for(int z = b; z < j; z++)
        {
            if(s[i][z] != 'X')
            {
                x = 0;
                break;
            }
        }
        if(!x)
            break;
        i++;
    }
    if((i - a) * (j - b) == res)
        cout << "YES";
    else
        cout << "NO";
}