#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#include <conio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

int Abs (int x) {return (x >= 0?x : -x);}

const LL p = 157;

int day[13] = {0, 31, 29, 31, 30,  31,  30,  31,  31,  30,  31,  30,  31};
int sum[13] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};

struct Node
{
    string a;
    int sec, id;

    Node()
    {
        sec = 0;
        a = "";
        id = -1;
    }

    Node(string x, int q)
    {
        id = q;
        a = x;
    
        int m, d, h, min, s;

        x[5] -= '0';
        x[6] -= '0';
        x[8] -= '0';
        x[9] -= '0';
        x[11] -= '0';
        x[12] -= '0';
        x[14] -= '0';
        x[15] -= '0';
        x[16] -= '0';
        x[17] -= '0';
        x[18] -= '0';

        m = x[5] * 10 + x[6];
        d = x[8] * 10 + x[9];
        h = x[11] * 10 + x[12];
        min = x[14] * 10 + x[15];
        s = x[17] * 10 + x[18];

        sec = (sum[m - 1] + max(d - 1, 0)) * 24 * 60 * 60 + h * 60 * 60 + min * 60 + s;
    }
};

bool cmp(Node a, Node b)
{
    return (a.sec < b.sec || (a.sec == b.sec && a.id < b.id));
}

bool solve()
{   
    string a;

    int n, m;

    scanf("%d %d", &n, &m);

    vec<Node> x;
    
    int sz = 0;

    getline(cin, a);
    while(getline(cin, a)) x.push_back(Node(a, sz)), sz++;

    sort(ALL(x), cmp);

    int l, r, mid, p;

    for(int i(0);i < sz;i++)
    {
        l = 0, r = i;

        while(r - l > 1)
        {
            mid = (l + r) >> 1;

            if(x[i].sec - n + 1 <= x[mid].sec) r = mid;
            else l = mid + 1;
        }

        if(x[i].sec - n + 1 <= x[l].sec) p = l;
        else if(x[i].sec - n + 1 <= x[r].sec) p = r;
        else continue;

        if(i - p + 1 >= m)
        {
            for(int j(0);j < 19;j++) cout << x[i].a[j];
            cout << '\n';
            return true;
        }
    }

    puts("-1");

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}