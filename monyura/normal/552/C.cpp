#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c.size())

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

map<ll, int> used;
vector<ll> vec(1, 1);
bool firstPart;
ll target;
ll res = 0;

void rec(int pos, int n, ll here) {
    if (pos == n) {
        if (firstPart) {
            used[here]++;
        }
        else {
            auto iter = used.find(target - here);
            if (iter != used.end())
                res += iter->second;
        }
    }
    else {
        rec(pos+1,n,here - vec[pos]);
        rec(pos+1,n,here);
        rec(pos+1,n,here + vec[pos]);
    }
}

void run()
{
    ll w;
    int m;
    cin>>w>>m;
    if (w == 2) {
        cout<<"YES"<<endl;
        return;
    }
    while (vec.back() * w <= 2*m) {
        vec.push_back(vec.back() * w);
    }
    if (vec.size() < 2)
        vec.push_back(vec.back() * w);
    firstPart = true;
    used.clear();
    rec(0,vec.size()/2, 0);
    firstPart = false;
    target  = m;
    res = 0;
    rec(vec.size()/2, vec.size(), 0);
    puts(res ? "YES" : "NO");
}



int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen("../" prob ".in","r",stdin);
    freopen("../" prob ".out","w",stdout);
#else
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#endif
#else
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}