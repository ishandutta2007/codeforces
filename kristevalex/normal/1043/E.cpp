#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

struct VAL
    {
    long long x, y, ind;


    operator< (VAL over)
        {
        return (x-y) < (over.x-over.y);
        }


    };


vector<VAL> data;
vector<long long> ansers;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> m;

    vector<pair<int, int>> pairs(m);

    data.resize(n);
    ansers.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i].x >> data[i].y;
        data[i].ind = i;
        }

    for (int i = 0; i < m; i++)
        {
        cin >> pairs[i].first >> pairs[i].second;
        --(pairs[i].first);
        --(pairs[i].second);
        }


    for (int i = 0; i < m; i++)
        {
        int ind1 = pairs[i].first, ind2 = pairs[i].second;

        long long value = min(data[ind1].x + data[ind2].y, data[ind1].y + data[ind2].x);

        ansers[ind1]-= value;
        ansers[ind2]-= value;
        }


    sort(data.begin(), data.end());


    long long cur_sum = 0;
    for (int i = 0; i < n; i++)
        {
        int num = data[i].ind;
        ansers[num]+= data[i].y*i + cur_sum;
        cur_sum+= data[i].x;
        }

    cur_sum = 0;
    for (int i = n-1; i >= 0; --i)
        {
        int num = data[i].ind;
        ansers[num]+= data[i].x*(n-1-i) + cur_sum;
        cur_sum+= data[i].y;
        }




    for (int i = 0; i < n; i++)
        {
        cout << ansers[i] << " ";
        }

    return 0;
    }