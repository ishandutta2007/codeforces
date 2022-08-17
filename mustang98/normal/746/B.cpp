#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;

int main()
{
    string s;
    int N;
    cin >> N;
    cin >> s;

    deque<char> d;
    if (N % 2 == 1)
    {
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                d.push_front(s[i]);
            }
            else
            {
                d.push_back(s[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                d.push_back(s[i]);
            }
            else
            {
                d.push_front(s[i]);
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << d.back();
        d.pop_back();
    }
    return 0;
}