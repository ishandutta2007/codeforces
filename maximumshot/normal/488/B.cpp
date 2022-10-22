#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}

using namespace std;

bool check(vec<int> a)
{
    if((a[0] + a[1] + a[2] + a[3]) == 4 * (a[3] - a[0]) && 2 * (a[3] - a[0]) == (a[1] + a[2])) return true;
    else return false;
}

bool solve()
{
    int n;

    cin >> n;

    vec<int> a(n), b;

    for(int i(0);i < n;i++) cin >> a[i];

    sort(ALL(a));

    b = a;

    if(n == 4)
    {
        if((a[0] + a[1] + a[2] + a[3]) == 2 * (a[1] + a[2]) && (a[1] + a[2]) == 2 * (a[3] - a[0]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }else if(n == 0)
    {
        cout << "YES\n";
        cout << 1 << '\n' << 1 << '\n' << 3 << '\n' << 3 << '\n';
    }else if(n == 1)
    {
        cout << "YES\n";
        cout << a[0] << '\n' << a[0] * 3 << '\n' << a[0] * 3 << '\n';
        return true;
    }else
    if(n == 2)
    {
        for(int i(1);i <= 1500;i++)
        {
            for(int j(1);j <= 1500;j++)
            {
                vec<int> tmp = a;
                a.push_back(i);
                a.push_back(j);
                sort(ALL(a));
                if(check(a))
                {
                    cout << "YES\n" << i << '\n' << j << '\n';
                    return true;
                }else
                    a = tmp;
            }
        }
        cout << "NO\n";
    }else
    {
        for(int i(1);i <= 2000;i++)
        {
            vec<int> tmp = a;
            a.push_back(i);
            sort(ALL(a));
            if(check(a))
            {
                cout << "YES\n" << i << '\n';
                return true;
            }else
                a = tmp;
        }

        cout << "NO\n";
    }

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}