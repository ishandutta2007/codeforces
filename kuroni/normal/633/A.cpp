#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, x, i;
    cin>>a>>b>>x;
    for (i = 0; i <= x/a; i++) if ((x - i*a) % b == 0) {cout<<"Yes"; return 0;}
    cout<<"No";
    return 0;
}