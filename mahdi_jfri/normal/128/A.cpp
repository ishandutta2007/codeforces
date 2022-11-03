#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s[10];
int a,b;
void dfs(int x,int y,int k)
{
    if(k > 6)
    {
        cout << "WIN";
        exit(0);
    }
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++)
        {
            a = x + i;
            b = y + j;
            if(a > 7 || b > 7 || a < 0 || b < 0)
                continue;
            if(a - k > -1 && (s[a-k][b] == 'S'))
                continue;
            if(a - k > 0 && s[a-k-1][b] == 'S')
                continue;
            dfs(a,b,k+1);
        }
}
int main()
{
    for(int i = 0; i < 8; i++)
        cin >> s[i];
    dfs(7,0,0);
    cout << "LOSE";
}