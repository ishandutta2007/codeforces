#include <iostream>
using namespace std;
int main()
{
    int k, r, i;
    cin>>k>>r;
    k = k % 10;
    for (i = 1; i <= 10; i++)
        if ((k*i % 10 == 0) || (k*i % 10 == r))
        {
            cout<<i<<'\n';
            return 0;
        }
}