#include <iostream>
#include <ios>
#include <stdio.h>
#include <vector>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    int a, b, k = 1, ans[1000], i;
    cin>>a>>b;
    ans[0] = b;
    while (b > a)
    {
        if (b % 2)
            {
                if (b % 10 == 1) b /= 10, ans[k++] = b;
                else {cout<<"NO"; return 0;}
            }
        else b /= 2, ans[k++] = b;
    }
    if (b < a) {cout<<"NO"; return 0;}
    cout<<"YES"<<'\n'<<k<<'\n';
    for (i = k - 1; i >= 0; i--) cout<<ans[i]<<" ";
}