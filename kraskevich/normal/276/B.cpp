#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second


void solve()
{
    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    for (int i = 0; i < s.length(); ++i)
        ++cnt[s[i] - 'a'];

    for(int j=0;;++j)
    {
        int odd=0;
        for(int i=0;i<26;++i)
            if(cnt[i]%2==1)
                ++odd;
        if(odd<=1)
        {
            if(j%2==0)
                cout<<"First";
            else
                cout<<"Second";
            return;
        }
        bool ok=false;
        for(int i=0;i<26;++i)
            if(cnt[i]&&cnt[i]%2==0)
            {
                --cnt[i];
                ok=true;
                break;
            }
        if(!ok)
            for(int i=0;i<26;++i)
                if(cnt[i])
                {
                    --cnt[i];
                    break;
                }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}