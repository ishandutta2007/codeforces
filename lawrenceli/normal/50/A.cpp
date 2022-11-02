#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int m, n, num1, num2;
    cin >> m >> n;
    num1=m*(n/2);
    if (n%2==1) num1+=m/2;
    num2=n*(m/2);
    if (m%2==1) num2+=n/2;
    cout << max(num1, num2) << endl;
}