#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n >> k;



    long long new_k = 2*k+1;
    /*if (k >= n)
        {
        cout << 1 << endl << 1;
        return 0;
        }*/

    m = (n+new_k-1)/new_k;

    cout << m << endl;

    data.resize(m);



    for (int i = 1, j = 0; i <= n; i+= new_k, ++j)
        {
        data[j] =  i;
        }

    int delta = n-data[m-1]-k;
    delta = max(delta, 0);

    for (int i = 0; i < m; i++)
        {
        cout << data[i] + delta << " ";
        }


    return 0;
    }