#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll n, k, r, minr= 10e10;
    ll prev = -1000001;
    vector <ll> v;
    int d[100010];
    string str;
    cin>>n>>k;
    cin>>str;
    k++;
    char c;
    for (int i=0;i<n;i++) if (str[i]=='0') v.push_back(i);
    for (int i=0;i<n;i++)
        if (str[i]=='0') {d[i]=0; prev=i;}
        else d[i]=abs(i-prev);
    prev = 1e6;
    for (int i=n-1;i>=0;i--)
        if (str[i]=='0') {d[i]=0; prev=i;}
        else if (abs(prev-i)<d[i]) d[i]=abs(prev-i);
    //for (int i=0;i<n;i++) cout<<d[i]<<' ';
    //cout<<endl;
    //for (int i=0;i<v.size();i++) cout<<v[i]<<' ';
    ll s=0,f=k-1, best;
    while (f<v.size())
    {
        if (v[s]+v[f]%2==0)
        {
            best = (v[s]+v[f])/2;
            r=(best-v[s])+d[best];
            if (r<minr) minr=r;
        }
        else
        {
            best = (v[s]+v[f])/2;
            r= v[f]-best+d[best];
            if (r<minr) minr=r;
            best++;
            r= best-v[s]+d[best];
            if (r<minr) minr=r;
        }
        f++;s++;
    }

    cout<<minr;
    return 0;
}