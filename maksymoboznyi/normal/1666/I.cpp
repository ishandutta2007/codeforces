#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <random>
#include <list>
#include <bitset>

using namespace std;

int X1,Y1,X2,Y2;

int ask(int r,int c)
{
    cout << "SCAN " << r << ' ' << c << endl;
    int y;
    cin >> y;
    return y;

    return abs(r-X1) + abs(r-X2) + abs(c-Y1) + abs(c-Y2);
}

vector<int> calc1(int A,int B,int C,int D)
{
/*
    A [ 1, 1, 1, 1]
    B [-1, 1,-1, 1]
    C [-1, 1, 1, 1]
    D [1, -1, 1, 1]
*/

    int x1 = (A-C)/2;
    int y1 = (A-D)/2;

    int x2 = (C-B)/2;
    int y2 = (B+D)/2;

    return {x1,y1,x2,y2};
}

vector<int> calc2(int A,int B,int C,int D)
{
/*
    A [ 1, 1, 1,  1]
    B [-1, 1,-1,  1]
    C [-1, 1, 1,  1]
    D [1,  1, 1, -1]
*/

    int x1 = (A-C)/2;
    int y1 = (B+D)/2;

    int x2 = (C-B)/2;
    int y2 = (A-D)/2;

    return {x1,y1,x2,y2};

}

int try_(int a,int b,int c, int d)
{
    cout << "DIG " << a << ' ' << b << endl;
    int q;
    cin >> q;
    if (q)
    {
        cout << "DIG " << c << ' ' << d << endl;
        int e;
        cin >> e;
        assert(e);
        return 1;
    }
    return 0;
}

void solve()
{
    int n,m;
    cin >> n >> m;

    /*while(true){
        X1 = rand()%n + 1;
        Y1 = rand()%m + 1;
        X2 = rand()%n + 1;
        Y2 = rand()%m + 1;

        if (X1 == X2 && Y1 == Y2)
        {

        } else {
            break;
        }
    }

    cout << X1 << ',' << Y1 << ' ' << X2 << ',' << Y2 << endl;*/

    int A = ask(1, 1) + 4; //  x1 + y1 + x2 + y2 - 4
    int B = ask(n, 1) + 2 - n - n; //- x1 + y1 - x2 + y2 + n + n - 2


    int xsum = (A-B)/2;

    int ysum = (A+B)/2;

    int xmid = xsum / 2;
    int ymid = ysum / 2;

    int C = ask(xmid, 1) + 2; // -x1 + y1 + x2 + y2 - 2

    int D = ask(1, ymid) + 2; //  x1 - y1 + x2 + y2 - 2 or x1 + y1 + x2 - y2 - 2

    vector<int> v1 = calc1(A,B,C,D);
    vector<int> v2 = calc2(A,B,C,D);

    if (!try_(v1[0],v1[1],v1[2],v1[3]))
        try_(v2[0],v2[1],v2[2],v2[3]);

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}