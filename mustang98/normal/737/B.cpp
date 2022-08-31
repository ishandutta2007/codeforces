#include <bits/stdc++.h>

using namespace std;

const int max_n= 200005;

char s[max_n];

vector<int> v, kol;

int main()
{
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    scanf(" %s", s);
    int k0 = 0;
    int kolkor = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0') k0++;
        else
        {
            if (k0)
            {
                v.push_back(k0);
                kol.push_back(k0 / b);
                kolkor += kol.back();
                k0 = 0;
            }
        }
    }
    if (k0) v.push_back(k0);
    kolkor += k0 / b;

    int ans = kolkor - a + 1;
    cout << ans << '\n';
    int d = 0;
    for (int i = 0; ans; i++)
    {
        if (s[i] == '1')
        {
            d = 0;
            continue;
        }
        d++;
        if (d == b)
        {
            printf("%d ", i + 1);

            ans--;
            d = 0;
        }
    }
}