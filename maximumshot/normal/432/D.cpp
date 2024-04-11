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

int C[123456] = {0};

vec<int> preff(string a)
{
    vec<int> pi((int)a.size());

    for(int i(1);i < (int)a.size();i++)
    {
        int j = pi[i - 1];
        while(j > 0 && a[j] != a[i]) j = pi[j - 1];
        j += (a[i] == a[j]);
        pi[i] = j;
    }

    return pi;
}

bool solve()
{   
    string a;   
    cin >> a;

    vec<int> pi = preff(a);

    for(int i((int)a.size() - 1);i >= 0;i--) C[pi[i]]++;
    for(int i((int)a.size() - 1);i >= 0;i--) C[pi[i]] += C[i + 1];

    vec<bool> ans((int)a.size(), 0);

    int j = (int)ans.size(), cnt = 0;

    while(j)
    {
        ans[j - 1] = 1; 
        cnt++;
        j = pi[j - 1];
    }

    printf("%d\n", cnt);

    for(int i(0);i < (int)a.size();i++)
        if(ans[i]) 
            printf("%d %d\n", i + 1, C[i + 1] + 1);

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}