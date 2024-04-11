#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    for (int i=100; i>=0; i--)
    {
        if (a%i==0 && b%i==0) return i;
    }
}

int main()
{
    int n, m[2], p=0;
    cin >> m[0] >> m[1] >> n;
    while (true)
    {
        n-=gcd(n, m[p]);
        p=(p+1)%2;
        if (n<0)
        {
            cout << p << endl;
            return 0;
        }
    }
}