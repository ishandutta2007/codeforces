#include <iostream>

using namespace std;
bool is_prime(int a)
{
    for (int i = 2; i * i <= a; i++)
        if (a%i == 0)
            return false;
    return true;
}
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= 1005; i++)
        if (!is_prime(n*i+1))
        {
            cout << i ;
            return 0;
        }
    return 0;
}