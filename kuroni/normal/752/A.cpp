#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;
main()
{
    int n, m, k, r, l;
    cin>>n>>m>>k;
    r = (k - 1)/(2 * m) + 1;
    l = ((k - 2 * (r - 1) * m - 1))/2 + 1;
    cout<<r<<" "<<l<<" ";
    if (k % 2 == 0) cout<<"R"; else cout<<"L";
}