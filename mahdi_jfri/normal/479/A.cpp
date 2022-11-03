#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    cin >> a[0] >> a[1] >> a[2];
    int b[50];
    b[0]=a[0]+a[1]+a[2];
    b[1]=a[0]*a[1]+a[2];
    b[2]=a[0]*a[1]*a[2];
    b[3]=a[0]+a[1]*a[2];
    b[4]=(a[0]+a[1])*a[2];
    b[5]=a[0]*(a[1]+a[2]);
    cout <<*max_element(b,b+6);
}