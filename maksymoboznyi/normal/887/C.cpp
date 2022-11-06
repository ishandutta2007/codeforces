#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 1e6;

const int     g[6][8] ={13, 14, 5, 6, 17, 18, 21, 22, 15, 16, 7, 8, 19, 20, 23, 24, 24, 22, 1, 3, 5, 7, 9, 11, 23, 21, 2, 4, 6, 8, 10, 12, 16, 14, 3, 4, 17, 19, 10, 9, 15, 13, 1, 2, 18, 20, 12, 11};
const int     g1[8] = {15, 16, 7, 8, 19, 20, 23, 24};
const int     g2[8] = {24, 22, 1, 3, 5, 7, 9, 11};
const int     g3[8] = {23, 21, 2, 4, 6, 8, 10, 12};
const int     g4[8] = {16, 14, 3, 4, 17, 19, 10, 9};
const int     g5[8] = {15, 13, 1, 2, 18, 20, 12, 11};



int a[24];

void move_left(int i)
{
    int v = a[g[i][6]-1];
    for (int j = 6; j > 0; j-=2)
    {

        a[g[i][j]-1] = a[g[i][j-2]-1];
    }
    a[g[i][0]-1]=v;
    v = a[g[i][7]-1];
    for (int j = 7; j > 1; j-=2)
        a[g[i][j]-1] = a[g[i][j-2]-1];
    a[g[i][1]-1]=v;
}

bool check(int i)
{
    return (a[i] == a[i+1] && a[i+1] == a[i+2] && a[i+2] == a[i+3]);
}
bool ch()
{
    return (check(0) && check(4) && check(8) && check(12) && check(16) && check(20));
}
bool is_in(int i, int j)
{
    return j-i <= 3;
}
int get(int i)
{
    return i - i%4;
}
int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 24; i++)
        cin >> a[i];
    for (int i = 0; i < 6; i++)
    {
        move_left(i);
        if (ch())
        {
            cout << "YES";
            return 0;
        }
        move_left(i);
        move_left(i);
        if (ch())
        {
            cout << "YES";
            return 0;
        }
        move_left(i);
    }
    cout << "NO";
    return 0;
}