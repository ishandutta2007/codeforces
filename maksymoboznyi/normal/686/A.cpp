#include <iostream>

using namespace std;
char x;
long long n;
long long g,k,m;
int main()
{   cin>>m>>n;
    g=0;
    for(long long i=0;i<m;i++)
    {
        cin>>x>>k;
        if (x=='+') {n+=k;}else
            {
                if (k>n){g++;}else {n-=k;}

            }
    }
    cout<<n<<' '<<g;
    return 0;
}