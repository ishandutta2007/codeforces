#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

long long n, S, C1 = 0, H, U;

vector<long long> ansers;
vector<long long> data;

void fill_circle(int ind)
    {
    if (ansers[ind] >= 0) return;

    ansers[ind] = ind;



    fill_circle(data[ind]);

    }

void fill_(int ind)
    {
    if (ansers[ind] >= 0) return;


    if (ansers[ind] == -2)
        {
        ansers[ind] = -3;
        fill_circle(ind);
        return;
        }

    ansers[ind] = -2;
    fill_(data[ind]);

    }



void fill_line(int ind)
    {
    if (ansers[ind] >= 0) return;

    fill_line(data[ind]);

    ansers[ind] = ansers[data[ind]];




    }

int main()
    {
    //FAST;


    cin >> n;

    ansers.resize(n);

    data.resize (n);

    for (int i = 0; i < n; i++)
        {
        cin >> data[i];
        data[i]--;
        ansers[i] = -1;
        }

    for (int i = 0; i < n; i++)
        {
        fill_(i);
        fill_line(i);
        }


    for (int i = 0; i < n; i++)
        {
        cout << ansers[i]+1 << endl;
        }
    return 0;
    }