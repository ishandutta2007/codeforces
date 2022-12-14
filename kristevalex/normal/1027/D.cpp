#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> ansers;
vector<long long> data;
vector<long long> cost;

long long ans = 0, cur_min_cost;

void fill_circle(int ind)
    {
    //cout << "hello";


    if (cost[ind] < cur_min_cost) cur_min_cost = cost[ind];


    if (ansers[ind] == -3)
        {
        ans+= cur_min_cost;

        //cout << cur_min_cost << " ";
        return;
        }


    fill_circle(data[ind]);
    }

void fill_(int ind)
    {
    if (ansers[ind] == 1) return;

    if (ansers[ind] == -2)
        {
        ansers[ind] = -3;
        cur_min_cost = 100000000000;
        fill_circle(data[ind]);
        return;
        }

    ansers[ind] = -2;
    fill_(data[ind]);

    }

void close_(int ind)
    {
    if (ansers[ind] == 1) return;

    ansers[ind] = 1;

    close_(data[ind]);
    }

int n;

int main()
    {
    FAST;


    cin >> n;

    data.resize(n);
    ansers.resize(n);
    cost.resize(n);


    for (int i = 0; i < n; i++)
        {
        cin >> cost[i];
        ansers[i] = 0;
        }

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        data[i]--;
        }


    for (int i = 0; i < n; i++)
        {
        fill_ (i);
        close_ (i);
        }

    cout << ans;

    return 0;

    }