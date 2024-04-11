#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
struct ex
{
    int bal;
    int ref;
};
ex m[100000];

bool cmp(ex a, ex b)
{
    return a.ref < b.ref;
}

int main()
{
    int n, r, avg;
    long long sum = 0;
    cin >> n >> r >> avg;
    for (int i = 0 ; i < n; i++)
    {
        cin >> m[i].bal >> m[i].ref;
        sum += m[i].bal;
    }
    if (sum >= avg*1ll*n)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(m, m+n, cmp);
    long long kol = avg*1ll*n - sum;
     //cout << kol << endl;
    long long kolR = 0;
    int i = 0;
    while (kol > 0)
    {
        long long dos = r - m[i].bal;
        if (kol >= dos)
        {
            kol -= dos;
            kolR += m[i].ref*dos;
        }
        else
        {
            kolR +=m[i].ref*kol;
            kol = 0;
        }
        i++;
        //cout << m[i].bal <<" " << m[i].ref << " " << kol << endl;
    }
    cout << kolR << endl;


}