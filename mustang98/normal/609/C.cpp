#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;



int main()
{
    ll n, s, sum=0,a,r=0;
    cin >>n;
    vector <int> m;
    for (int i=0;i<n;i++)
    {
        cin>>a;
        m.push_back(a);
        sum+=a;
    }
    sort(m.begin(), m.end());
    if (sum%n==0)
    {
        s=sum/n;
        int b=0, e=n-1;
        while (b<e)
        {
            if (m[b]==s) {b++; continue;}
            if (m[e]==s) {e--; continue;}
            m[b]++;
            m[e]--;
            r++;
        }
        cout<<r;
    }
    else
    {
        s=sum/n;
        r=0;ll r1=0;
        for (int i=0;i<n;i++)
            if (m[i]<s) r+=abs(m[i]-s);
            else if (m[i]>s+1) r1+=abs(m[i]-s-1);
        cout<<max(r1,r);
    }

    return 0;
}