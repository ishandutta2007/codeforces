#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <queue>
#include <stack>

#define FOR(i,a,b) for(int i = a; i <= b; i++) 
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define FR(i,a) for(int i = 0; i < a; i++)
#define DR(i,a) for(int i = a-1; i >= 0; i--)
#define REP(i,a) for(int i = 0; i < a; i++)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define For(i,a,b) for(int i = a; i <= b; i++)

#define sqr(x) (x)*(x)
#define dout debug && cout 
#define ll long long
#define sz size()
#define ull unsigned long long
#define pb push_back
#define oo 1000000000000000002LL
/* DEBUGGING */
bool debug = false;
/* MAIN PROGRAM */

using namespace std;
/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
string convertToString(long long a) {
    string res = ""; if (!a) return "0";
    while (a) { res = (char)(a % 10 + 48) + res;  a /= 10; }
    return res;
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}
/**************************CODE HERE*****************************/
#define maxn 100003
int n,m;
long long d[maxn];
int Trace[maxn];
vector< pair<int, long long> > a[maxn];
priority_queue< pair<long long,int > > Heap;
vector<int> res;
pair<long long,int > tmp;
bool dd[maxn];
int main()
{
//    freopen("test.in","r",stdin);
  //  freopen("test.out","w",stdout);
    cin >> n >> m;
    int u,v;
    long long val,cost;
    FOR(i,1,m)
    {
        cin >> u >> v >> val;
        a[u].push_back(make_pair(v,val));
        a[v].push_back(make_pair(u,val));
    }
    FOR(i,1,n) d[i] = oo;
    d[1] = 0;
    memset(dd,true,sizeof(dd));
    Heap.push(make_pair(0,1));
    do
    {
        tmp = Heap.top();
        Heap.pop();
        u = tmp.second; val = -tmp.first;
        if (!dd[u]) continue;
        dd[u] = false;
        FR(j,a[u].size())
        {
            v = a[u][j].first;
            cost = a[u][j].second;
            if (dd[v] && d[v] > d[u] + cost)
            {
                d[v] = d[u] + cost;
                Trace[v] = u;
                Heap.push(make_pair(-d[v],v));
            }
        }
    } while (!Heap.empty());
    if (d[n] == oo)
    {
        cout << -1 << endl;
        return 0;
    }
    res.resize(0);
    int i = n;
    res.push_back(i);
    while (i != 1)
    {
        i = Trace[i];
        res.push_back(i);
    }
    DOWN(i,res.size()-1,0) cout << res[i] << " " ;
    
    return 0;
}