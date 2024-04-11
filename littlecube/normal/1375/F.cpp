/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int A, B, C, mx;
signed main()
{
    fast;
    cin >> A >> B >> C;
    cout << "First" << endl;
    if (A > B && A > C)
    {
        cout << A - B + A - C << endl;
        int k = 0;
        cin >> k;
        if (k == 1)
        {
            A += A - B + A - C;
            cout << A - B + A - C << endl;
            cin >> k;
            if (k == 2)
            {
                B += A - B + A - C;
                cout << B - A << endl;
                cin >> k;
                assert(k == 0);
            }
            else if (k == 3)
            {
                C += A - B + A - C;
                cout << C - A << endl;
                cin >> k;
                assert(k == 0);
            }
        }
        else if (k == 2)
        {
            B += A - B + A - C;
            cout << B - A << endl;
            cin >> k;
            assert(k == 0);
        }
        else if (k == 3)
        {
            C += A - B + A - C;
            cout << C - A << endl;
            cin >> k;
            assert(k == 0);
        }
    }
    if (B > A && B > C)
    {
        cout << B - A + B - C << endl;
        int k = 0;
        cin >> k;
        if (k == 2)
        {
            B += B - A + B - C;
            cout << B - A + B - C << endl;
            cin >> k;
            if (k == 1)
            {
                A += B - A + B - C;
                cout << A - B << endl;
                cin >> k;
                assert(k == 0);
            }
            else if (k == 3)
            {
                C += B - A + B - C;
                cout << C - A << endl;
                cin >> k;
                assert(k == 0);
            }
        }
        else if (k == 1)
        {
            A += B - A + B - C;
            cout << A - B << endl;
            cin >> k;
            assert(k == 0);
        }
        else if (k == 3)
        {
            C += B - A + B - C;
            cout << C - B << endl;
            cin >> k;
            assert(k == 0);
        }
    }
    if (C > B && C > A)
    {
        cout << C - A + C - B << endl;
        int k = 0;
        cin >> k;
        if (k == 3)
        {
            C += C - A + C - B;
            cout << C - A + C - B << endl;
            cin >> k;
            if (k == 2)
            {
                B += C - A + C - B;
                cout << B - C << endl;
                cin >> k;
                assert(k == 0);
            }
            else if (k == 1)
            {
                A += C - A + C - B;
                cout << A - C << endl;
                cin >> k;
                assert(k == 0);
            }
        }
        else if (k == 2)
        {
            B += C - A + C - B;
            cout << B - C << endl;
            cin >> k;
            assert(k == 0);
        }
        else if (k == 1)
        {
            A += C - A + C - B;
            cout << A - C << endl;
            cin >> k;
            assert(k == 0);
        }
    }
}