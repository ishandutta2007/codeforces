#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    int a,n,k,rez=0;
    int m[100];
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>m[i];
    a=m[k-1];
    for (int i=0;i<n;i++)
        if (m[i]>0 && m[i]>=a) rez++;
    cout<<rez;
}