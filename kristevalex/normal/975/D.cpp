#include <bits/stdc++.h>
using namespace std;

long long n, a, tmp1, tmp2;


struct prisrak
    {
    long long speed_vdol, speed_ort;

    prisrak (long long speed_x, long long speed_y)
        {
        speed_vdol = speed_x   + speed_y*a;
        speed_ort  = speed_x*a - speed_y;
        }

    prisrak () :
        speed_vdol (0),
        speed_ort (0) {}

    bool operator< (prisrak over)
        {
        if (speed_ort != over.speed_ort) return (speed_ort < over.speed_ort);
        return (speed_vdol < over.speed_vdol);
        }
    };




int main()
    {
    cin >> n >> a >> tmp1;

    vector<prisrak> data(n);



    for (long long i = 0; i < n; i++)
        {
        cin >> tmp1 >> tmp1 >> tmp2;
        data[i] = prisrak(tmp1, tmp2);
        }

    sort(data.begin(), data.end());

    for (long long i = 0; i < n; i++)
        {
        //cout << data[i].speed_ort << " " << data[i].speed_vdol << endl;
        }


    long long sum = 0;

    for (long long i = 0; i < n; i++)
        {
        long long speedi = data[i].speed_ort;
        long long speedi_ = data[i].speed_vdol;
        long long j = i;
        for ( ; j < n; j++)
            {
            if (speedi != data[j].speed_ort) {j--; break;}
            }
        if (j == n) j--;

        long long k_prev = i;
        for (long long k = i; k <= j; k++)
            {
            if (k == j || data[k_prev].speed_vdol != data[k].speed_vdol)
                {
                if (data[k_prev].speed_vdol != data[k].speed_vdol) k--;
                //cout << "adding, i:" << i << ", j:" << j << ", k:" << k << ", k_prev:" << k_prev << ", value:" << (k - k_prev + 1)*(j-i+1 - (k - k_prev + 1)) << endl;
                sum+= (k - k_prev + 1)*(j-i+1 - (k - k_prev + 1));
                k_prev = k+1;
                }
            }
        i = j;
        }


    cout << sum;

    return 0;
    }