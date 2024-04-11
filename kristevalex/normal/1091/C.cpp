#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



long long get_ans(long long pieces)
    {



    return (pieces)*(pieces - 1)/2*(n/pieces) + pieces ;
    }



int main()
    {
    //FAST;


    cin >> n;

    long long SQRT = sqrt(n);

    for (long long i = 1; i <= SQRT; i++)
       {
       //cout << i;

       if (n%i == 0)
           {
           data.push_back(i);

           if (SQRT*SQRT != n || i != SQRT)
                data.push_back(n/i);
           }
       }




    sort(data.begin(), data.end());

    for (int i = 0; i < data.size(); i++)
        {
        //cout << data[i] << " ";
        }


    for (int i = 0; i < data.size(); i++)
        {
        cout << get_ans(data[i]) << " ";
        }



    return 0;
    }