#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;



int main()
{
    ll rez=0, n, M,a;
    ll m[12]={0};
    cin>>n>>M ;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        m[a]++;
    }
    for (int i=1;i<M;i++)
        for (int j=i+1;j<=M;j++) rez+=m[i]*m[j];
    cout<<rez;
    return 0;
}