#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    string H, A;

    cin >> H >> A;

    int cnt[2][100] = {0};
    bool used[2][100] = {false};

    int n;
    cin >> n;

    for(int i(0);i < n;i++)
    {
        char team, card;
        int num, t;
        cin >> t >> team >> num >> card;

        if(used[team != 'h'][num]) continue;

        if(card == 'r') 
            cout << (team == 'h'?H : A) << ' ' << num << ' ' << t << '\n', used[team != 'h'][num] = 1;
        else
        {
            cnt[team != 'h'][num]++;
            if(cnt[team != 'h'][num] == 2)
                cout << (team == 'h'?H : A) << ' ' << num << ' ' << t << '\n',
                used[team != 'h'][num] = 1;
        }
    }


    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}