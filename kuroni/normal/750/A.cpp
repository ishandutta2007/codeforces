#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
#define ll long long
using namespace std;

int main()
{
    int k, n, i = 0;
    cin>>n>>k;
    k = 240 - k;
    while ((k - 5*(i + 1) >= 0) && (i < n)) k -= 5 * (++i);
    cout<<i;
}