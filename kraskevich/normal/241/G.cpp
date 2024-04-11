#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>

using namespace std;


#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;

//-----------------TEMPLATE STARTS HERE---------------//
long long gcd64(long long a, long long b)
{
    if (!a)
        swap(a, b);
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

int gcd32(int a, int b)
{
     if (!a)
        swap(a, b);
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

long long lcm64(long long a, long long b)
{
    return a / gcd64(a, b) *  b;
}

int lcm32(int a, int b)
{
    return a / gcd32(a, b) * b;
}

template <class T> void read(T a, int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

template <class T> void read(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
}

template <class T> void print(T a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}

template <class T> void print(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
}
//---------------TEMPLATE ENDS HERE---------------//
    


int main()
{
    ios_base::sync_with_stdio(0);
    
    cout << 303 << endl;
    cout << 0 << " " << 200 * 1000 << endl;
    int now = 200 * 1000;
    for (int i = 0; i < 301; ++i)
    {
        now += 2 * (301 - i + 1);
        cout << now << " " << 301 - i << endl;
    }
    cout << 800 * 1000 << " " << 1000 * 1000 << endl;

    //int w;
    //cin >> w;
    
    return 0;
}