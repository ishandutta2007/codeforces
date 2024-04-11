#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int solve(int a , int b)
{
    if(a >= b)
        return a-b;
    return ((b&1)?solve(a,(b+1)/2)+1:solve(a,b/2))+1;
}
int main()
{
    int a,b;
    cin >> a >> b;
    cout << solve(a,b);
}