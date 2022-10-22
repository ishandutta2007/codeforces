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

string mn(string aa, string bb)
{
    string a, b;
    bool f = 0;
    int pos = 0;
    for(pos;pos < (int)aa.size();pos++) if(aa[pos] != '0') break;
    
    if(pos == (int)aa.size()) a = "0";
    else a = aa.substr(pos);

    pos = 0;

    for(pos;pos < (int)bb.size();pos++) if(bb[pos] != '0') break;
    
    if(pos == (int)bb.size()) b = "0";
    else b = bb.substr(pos);

    if((int)a.size() < (int)b.size()) return a;
    else if((int)a.size() > (int)b.size()) return b;
    else
    {
        for(int i(0);i < (int)a.size();i++)
        {
            if(a[i] < b[i]) return a;
            if(a[i] > b[i]) return b;
        }
    }

    return a;
}

bool solve()
{
    int n;

    cin >> n;

    string a, tmp, ans = "-1";

    cin >> a;

    ans = a;

    for(int i(0);i < n;i++)
    {
        tmp.clear();
        for(int j(i);j < n;j++) tmp += a[j];
        for(int j(0);j < i;j++) tmp += a[j];
        int delt = tmp[0] - '0';
        delt = 10 - delt;
        //cout << tmp << ' ';
        for(int j(0);j < n;j++) tmp[j] = ((tmp[j] - '0') + delt) % 10 + '0';
        ans = mn(ans, tmp); 
        //cout << tmp << ' ' << delt << '\n';
    }

    string q(n - (int)ans.size(), '0');

    cout << q + ans << '\n';

    return true;
}
    
int main()
{
    //while(solve());   
    solve();

    return 0;
}