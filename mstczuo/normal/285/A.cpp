# include <iostream>
# include <cstdio>
using  namespace std;

int n,k;

int main()
{
    cin >>  n >> k;
    int t=n;
    for(int i=1;i<=k;i++){
        cout << t << ' ';
        t--;
    }
    for(int i=1;i<=t;i++)
        cout << i << ' ';

    return 0;
}