#include <iostream>
int a, b, c, x, y, z;
main()
{
    std::cin>>a>>x>>b>>y>>c>>z;
    std::cout<<3<<'\n'<<a+b-c<<" "<<x+y-z<<'\n'<<a-b+c<<" "<<x-y+z<<'\n'<<b+c-a<<" "<<y+z-x;
}