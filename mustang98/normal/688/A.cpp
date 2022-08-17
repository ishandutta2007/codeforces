#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int main() 
{
    int n, d;
    int k=0;
    int m=0;
    cin>>n>>d;
    for (int i = 0;i<d;i++)
    {
        string s;
        cin>>s;
        for (int j=0;j<n;j++)
        {
            if (s[j]=='0')
            {
                k++;
                m=max(m,k);
                break;
            }
            if (j==n-1) {k=0;}
        }
    }
    cout<<m;
    return 0;
}