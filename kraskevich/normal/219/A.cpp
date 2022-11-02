#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>
#define ALL(x) x.begin(), x.end()
#define PB push_back

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;



//---------------------------------------//
//Reading and printing arrays and vectors//
template<class T> void read(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
}

template<class T> void read(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

template<class T> void print(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";
}

template<class T> void print(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void wait()
{
    int w;
    cin >> w;
}
//-----------------------------------------//


int main()
{
    ios_base::sync_with_stdio(0);
    
    int k;
    string s;
    
    cin >> k >> s;
    
    vector<int> cnt(256, 0);
    
    for (int i = 0; i < s.length(); ++i)
        ++cnt[s[i]];
    
    bool ok = true;
    for (int i = 0; i < 256; ++i)
        if (cnt[i] % k != 0)
            ok = false;
        else
            cnt[i] /= k;
    
    if (!ok)
    {
        cout << -1;
        return 0;
    }
    
    for (int per = 0; per < k; ++per)
        for (int i = 0; i < 256; ++i)
            for (int j = 0; j < cnt[i]; ++j)
                cout << char(i);
    
    wait();
            
    return 0;
}