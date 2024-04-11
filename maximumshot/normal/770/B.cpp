#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <ctime >
#include <sstream>
using namespace std;
typedef unsigned long long int lli;
typedef vector<int> vi;
#define FOR(i, p, n) for(int i(p); i < n; i++)
#define FORR(i,p) for( i(p); i>=0; i--)
#define ALL(a) (a.begin()),(a.end())
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)
#define FORI(n) for(int i=0;i<n;i++)
#define sz(V) (int)V.size()
#define pb push_back
#define UN(x) (x).resize(unique(ALL((x))) - (x).begin());
#define mp make_pair
const int INF = 1000000000;
string  solve( string s)
{
    string f = s;
    string res;
    int ans(0);
    for (int i(s.size() - 1); i > 0; i--)
    {
        int tmp(0);
        for (int j(0); j < s.size(); j++)
        {
            tmp += s[j] - '0';
        }
        if (tmp > ans)  { ans = tmp; res = s; }
        s[i] = '9';
        int l(i-1);
        while (l > 0 && s[l] == '0') {
            s[l] = '9'; l--;
        }
        if(l>=0) s[l]--;
        i = l+1;
    }
    int tmp(0);
    for (int j(0); j < s.size(); j++)
    {
        tmp += s[j] - '0';
    }
    if (tmp > ans)  { ans = tmp; res = s; }
    while (res[0] == '0')
        res.erase(res.begin());
    return res;
}
 
int main()
{
    string s;
    cin >> s;
    cout << solve(s);
    return 0;
}