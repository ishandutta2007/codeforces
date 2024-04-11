#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
			 cin.tie(nullptr);                 \
	         cout.tie(nullptr)

vector<long long> ansers1(100007);

int data[100007] = {};

long long a, b, k, n, m, tmp, ans = 0, Size1 = 0;





int main()
    {
    FAST;


    cin >> a >> b;


    long long sum = a+b, maxn = 0;
    for (int i = 1; true; i++)
        {
        sum-= i;
        if (sum < 0)
            {
            //cout << 2345678;

            maxn = i;
            //cout << endl << maxn << endl;
            break;
            }
        }
    //cout << 2345678;
    //cout << maxn;

    data[maxn] = -1;



    bool swaped = false;
    if (a > b)
        {
        swap(a, b);
        swaped = true;
        }


    //cout << maxn<< endl;
    if (maxn%2 == 0 && a%maxn != 0)
        {
        //cout << "eghjk";
        if (a >= maxn/2)
            {
            data[maxn/2] = 1;
            ansers1[Size1] = maxn/2;
            a-= maxn/2;
            Size1++;
            }
        }


    for (int i = 1; i <= (maxn-1)/2; ++i)
        {
        //cout << a << " " << i << " " << Size1 << endl;

        if (a < maxn) break;
        if (a%maxn != i && a%maxn != maxn-i)
            {
            //cout << "a";
            data[i] = 1;
            ansers1[Size1] = i;
            ++Size1;
            //cout << ""
            data[maxn-i] = 1;
            ansers1[Size1] = (maxn-i);
            ++Size1;

            a-= maxn;
            }
        }
//cout << endl << maxn << endl;
     if (a)
         {
         data[a] = 1;
         ansers1[Size1] = a;
         Size1++;
         a = 0;
         }


    /*for (int i = 1; i < maxn; i++)
        {
        //cout << maxn << endl;
        //cout << "{" << i << "}: " << data[i] << endl;
        if (data[i] == 0) ansers2.push_back(i);
        }*/



     if (!swaped)
        {
        cout << Size1 << endl;

        for (int i = 0; i < Size1; i++)
            {
            cout << ansers1[i] << " ";
            }
        cout << endl;
        }


    cout << maxn-Size1-1 << endl;

    for (int i = 1; i < maxn; i++)
        {
        if (data[i] == 0) cout << i << " ";
        }
    cout << endl;



    if (swaped)
        {
        cout << Size1 << endl;

        for (int i = 0; i < Size1; i++)
            {
            cout << ansers1[i] << " ";
            }
        }
    cout << endl;

    return 0;
    }