#include <iostream>
int a[50], i = 0, n, t = 0;
main()
{
    std::cin>>n;
    while (t <= n)
    {
        a[++i] = i;
        t += i;
    }
    t -= i--;
    a[i] += n - t;
    std::cout<<i<<'\n';
    while (i > 0)
        std::cout<<a[i--]<<" ";
}