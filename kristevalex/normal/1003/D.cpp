#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)



int get_st (long long value)
    {
    int returned = 0;

    while(true)
        {
        if (value & 1) return returned;
        else
            {
            value = (value >> 1);
            returned++;
            }
        }
    }


long long pow2 (long long value)
    {
    if (value == 0) return 1;
    if (value == 1) return 2;


    long long ret = pow2(value/2);
    ret =  ret*ret;
    if (value & 1) return 2*ret;
    return ret;

    }


long long n, q, tmp;


long long data[40] = {};


int main()
    {
    //FAST;

    //cout << "k;lev " << (4<<1);

    cin >> n >> q;

    vector<long long> qwest (q, 0);


    vector<long long> ansers (q, 0);


    for (int i = 0; i < n; i++)
        {
        cin >> tmp;
        data[get_st(tmp)]++;

        }

        /*for (int i = 39; i >= 0; i--)
            {
            cout << data[i];
            } */

    for (int i = 0; i < q; i++)
        {
        cin >> qwest[i];
        }

    for (int num_test = 0; num_test < q; num_test++)
        {
        for (int i = 39; i >= 0; i--)
            {
            if (!data[i]) continue;

            long long curr = pow2(i);
            long long nead = qwest[num_test]/curr;

            if (!nead) continue;

            long long stock = min (nead, data[i]);
            ansers[num_test]+= stock;
            qwest[num_test]-= stock*curr;

            //cout << num_test << " stock " << stock << " curr "  << curr << " quest new " << qwest[num_test] << endl;
            }
        if (qwest[num_test]) ansers[num_test] = -1;
        }



    for (int i = 0; i < q; i++)
        cout << ansers[i] << endl;

    return 0;
    }