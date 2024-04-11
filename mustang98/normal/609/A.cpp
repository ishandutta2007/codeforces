#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;



int main()
{
    int a,n,K, kol=0;
    vector <int> m;
    cin>>n;
    cin>>K;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        m.push_back(a);
    }
    sort(m.begin(), m.end());
    for (int i=m.size()-1; i>=0; i--)
    {
        if (K>0) {K-=m[i]; kol++;}
        else break;
    }
    cout<<kol;
    return 0;
}