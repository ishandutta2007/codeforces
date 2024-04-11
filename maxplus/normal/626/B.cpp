#include <iostream>
#include <cstring>

using namespace std;

const int N = 201;
int n, r, g, b, ans[N][N][N];

int getans(int r, int g, int b)
{
    if (r + g + b == 1)
        return ((r == 1) << 2) + ((g == 1) << 1) + (b == 1);
    if (ans[r][g][b] != -1)
        return ans[r][g][b];
    int &ans = ::ans[r][g][b] = 0;
    if (r >= 2)
        ans |= getans(r - 1, g, b);
    if (g >= 2)
        ans |= getans(r, g - 1, b);
    if (b >= 2)
        ans |= getans(r, g, b - 1);
    if (r && g)
        ans |= getans(r - 1, g - 1, b + 1);
    if (b && g)
        ans |= getans(r + 1, g - 1, b - 1);
    if (b && r)
        ans |= getans(r - 1, g + 1, b - 1);
    return ans;
}

int main()
{
    memset(ans, 255, sizeof(ans));
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; cin.get(), ++i)
        if (cin.peek() == 'R')
            r++;
        else if (cin.peek() == 'G')
            g++;
        else
            b++;
    int msk = getans(r, g, b);
    if (msk & 1)
        cout << 'B';
    if (msk & 2)
        cout << 'G';
    if (msk & 4)
        cout << 'R';
    return 0;
}