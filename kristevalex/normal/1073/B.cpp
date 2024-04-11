#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> a;
vector<long long> b;

long long k, n, m, tmp, ans = 0;


int used[1000000];



int main()
    {


    cin >> n;

    a.resize(n);
    b.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];


    for (int i = 0; i < n+10; i++)
        {
        used [i] = 0;
        }

    int cur_ind = 0;

    for (int i = 0; i < n; i++)
        {
        if (used[b[i]] != 0)
            {
            cout << 0 << " ";
            }
        else
            {
            int counter = 0;
            while(true)
                {
                used[a[cur_ind]] = 1;
                counter++;

                //cout << "| " << cur_ind << " ";
                if(a[cur_ind] == b[i]) break;
                cur_ind++;

                }
            cur_ind++;


            cout << counter << " ";
            }
        }






    return 0;
    }