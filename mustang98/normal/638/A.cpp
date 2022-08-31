#include <iostream>

using namespace std;
int main()
{
    int n, a;
    cin>>n>>a;
    if (a%2) cout<<(a/2+1);
    else cout<<(n-a+2)/2;
    return 0;
}