#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

int main()
{
    int n,k,l,i[200000];
    long long h,kol=0;
    map <int,int> m1,m2;
    m1.clear();
    m2.clear();
    cin>>n>>k;
    for (l=0;l<n;l++)
    {
        cin>>i[l];
        m1[i[l]]++;
        m2[i[l]]=0;
    }
    for (l=0;l<n;l++)
    {
        m1[i[l]]--;
        h=(long long)i[l]*k;
        if (abs(h)<=1e9) {kol=(long long)kol+(long long)m2[i[l]]*m1[h]; m2[h]++;}
    }
    cout<<(long long)kol;
    return 0;
}