#include <iostream>
#include <cstdio>
using namespace std;
long long l,r;
int main()
{
    cin>>l>>r;
    puts("YES");
    for(long long i=l;i<=r-1;i+=2)
        cout<<i<<' '<<i+1<<endl;
    return 0;
}