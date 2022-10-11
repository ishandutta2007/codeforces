#include <iostream>

int n;

int main()
{
    std::cin >> n;
    std::cout << ((!(n & 1) && n >= 4) ? "YES" : "NO");
}