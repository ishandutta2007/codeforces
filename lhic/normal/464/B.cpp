#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

typedef long long ll;
typedef long double ld;

const int MAX_N = -1;


using namespace std;


struct pnt
{
    int p[3] = {0, 1, 2};
    ll x[3];
};

ll dist(pnt a, pnt b)
{
    ll ans = 0;
    for (int i = 0; i < 3; ++i)
        ans += (a.x[a.p[i]] - b.x[b.p[i]]) * (a.x[a.p[i]] - b.x[b.p[i]]);
    return ans;
}

int en[10];

pnt arr[100];


int main()
{
    for (int i = 0; i < 8; ++i)
        cin >> arr[i].x[0] >> arr[i].x[1] >> arr[i].x[2];
    en[0] = true;
    for (int i = 1; i < 8; ++i)
    {
        en[i] = true;
        do
        {
            ll dst = dist(arr[0], arr[i]);
            if (dst == 0)
                continue;
            for (int j = 1; j < 8; ++j)
            {
                if (en[j])
                    continue;
                en[j] = true;
                do
                {
                    if (dist(arr[0], arr[j]) != dst || dist(arr[i], arr[j]) != 2 * dst)
                        continue;
                    for (int k = 1; k < 8; ++k)
                    {
                        if (en[k])
                            continue;
                        en[k] = true;
                        do
                        {
                            if (dist(arr[0], arr[k]) != dst || dist(arr[i], arr[k]) != 2 * dst || dist(arr[j], arr[k]) != 2 * dst)
                                continue;
                            vector<int> oth;
                            for (int i1 = 1; i1 < 8; ++i1)
                            {
                                if (!en[i1])
                                    oth.push_back(i1);
                            }
                            do
                            {
                                bool fl1 = false;
                                bool fl2 = false;
                                bool fl3 = false;
                                bool fl4 = false;
                                do
                                {
                                    if (dist(arr[0], arr[oth[0]]) == 2 * dst && dist(arr[i], arr[oth[0]]) == dst && dist(arr[j], arr[oth[0]]) == 3 * dst && dist(arr[k], arr[oth[0]]) == dst)
                                    {
                                        fl1 = true;
                                        break;
                                    }
                                }
                                while (next_permutation(arr[oth[0]].p, arr[oth[0]].p + 3));

                                do
                                {
                                    if (dist(arr[0], arr[oth[1]]) == 3 * dst && dist(arr[i], arr[oth[1]]) == 2 * dst && dist(arr[j], arr[oth[1]]) == 2 * dst && dist(arr[k], arr[oth[1]]) == 2 * dst)
                                    {
                                        fl2 = true;
                                        break;
                                    }
                                }
                                while (next_permutation(arr[oth[1]].p, arr[oth[1]].p + 3));

                                do
                                {
                                    if (dist(arr[0], arr[oth[2]]) == 2 * dst && dist(arr[i], arr[oth[2]]) == dst && dist(arr[j], arr[oth[2]]) == dst && dist(arr[k], arr[oth[2]]) == 3 * dst)
                                    {
                                        fl3 = true;
                                        break;
                                    }
                                }
                                while (next_permutation(arr[oth[2]].p, arr[oth[2]].p + 3));

                                do
                                {
                                    if (dist(arr[0], arr[oth[3]]) == 2 * dst && dist(arr[i], arr[oth[3]]) == 3 * dst && dist(arr[j], arr[oth[3]]) == dst && dist(arr[k], arr[oth[3]]) == dst)
                                    {
                                        fl4 = true;
                                        break;
                                    }
                                }
                                while (next_permutation(arr[oth[3]].p, arr[oth[3]].p + 3));
                                if (fl1 && fl2 && fl3 && fl4)
                                {
                                    //cout << i << j << k;
                                    cout << "YES\n";
                                    for (int i = 0; i < 8; ++i)
                                    {
                                        for (int j = 0; j < 3; ++j)
                                        {
                                            cout << arr[i].x[arr[i].p[j]] << " ";
                                        }
                                        cout << "\n";
                                    }
                                    return 0;
                                }
                                for (int i = 0; i < oth.size(); ++i)
                                {
                                    arr[oth[i]].p[0] = 0;
                                    arr[oth[i]].p[1] = 1;
                                    arr[oth[i]].p[2] = 2;
                                }

                            }
                            while (next_permutation(oth.begin(), oth.end()));

                        }
                        while (next_permutation(arr[k].p, arr[k].p + 3));
                        en[k] = false;
                    }

                }
                while (next_permutation(arr[j].p, arr[j].p + 3));
                en[j] = false;
            }
        }
        while (next_permutation(arr[i].p, arr[i].p + 3));
        en[i] = false;
    }
    cout << "NO";
    return 0;
}