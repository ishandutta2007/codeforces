#include <iostream>
#include <cstring>
using namespace std;
char c[105];
void reverse (int d)
{
    int i;
    for(i=0;i<d/2+1;++i)
        swap(c[i],c[d-i]);
}
int main()
{
    int n,i;
    cin>>n>>c;
    for(i=1;i<=n;++i)
        if(n%i==0)
            reverse(i-1);
    cout<<c;
    return 0;
}