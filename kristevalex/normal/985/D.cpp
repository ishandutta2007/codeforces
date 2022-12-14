#include <bits/stdc++.h>
using namespace std;

long long N, H;

long long quantity(long long num)
    {
    if (num <= H) {return (num+1)*num/2;}
    num-= (H-1);
    //cout << num << endl;
    if ((num%2) == 0) {/*cout << (H-1)*H/2 << " " << H*num << " " << (num/2-1)*num/2 << endl;*/ return (H-1)*H/2 + H*num + (num/2-1)*num/2;}
    //cout << (H-1)*H/2 << " " << H*num << " " << (num/2-1)*(num/2) + num/2 << endl;
    return (H-1)*H/2 + H*num + (num/2-1)*(num/2) + num/2;
    }

int main()
    {
    cin >> N >> H;

    //cout << (quantity(64379857)) << endl;
    //cout << (quantity(64379858)) << endl << endl;
    //return 0;
    long long low = 0;
    long long high = 2*sqrt(N)+2;
    while (high - low > 1)
        {
        long long middle = (low + high)/2;
        //cout << middle << " " << quantity(middle) << endl;
        if (quantity(middle) >= N)
            high = middle;
        else
            low = middle;
        }

    cout << high;

    return 0;
    }