#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    cout<<(a+b)%n+n*((a+b)%n <= 0);
    return 0;
}