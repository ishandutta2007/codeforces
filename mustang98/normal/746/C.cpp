#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    int s, x1, x2, tt, ti, pt, d;
    cin >> s >> x1 >> x2 >> tt >> ti >> pt >> d;
    if (x1 == x2)
    {
        cout << 0;
        return 0;
    }
    if (ti <= tt)
    {
        cout << abs(x1 - x2) * ti;
        return 0;
    }
    int ansi = abs(x1 - x2) * ti;
    int anst = abs(x1 - x2) * tt;
    int wait = 0;

    int needd;
    if (x2 < x1) needd = -1;
    else needd = 1;
    while(true)
    {
        //cout << pt << ' ' << d << endl;
        if (pt == x1 && (pt == s || pt == 0))
        {
            break;
        }
        if (pt == x1 && d == needd)
        {
            break;
        }
        if (pt == s)
        {
            pt--;
            d = -1;
        }
        else if (pt == 0)
        {
            pt++;
            d = 1;
        }
        else if (d == 1)
        {
            pt++;
        }
        else if (d == -1)
        {
            pt--;
        }
        wait++;
    }
    wait *= tt;
    cout << min(ansi, anst + wait);
    return 0;
}