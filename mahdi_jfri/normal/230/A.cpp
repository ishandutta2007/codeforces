#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
pair<int,int>a[maxn];
int main()
{
    int n;
    ll s;
    cin >> s >> n;
    for(int i=0 ; i < n ;i++)
        cin >> a[i].first >> a[i].second;
    sort(a,a+n);
    for(int i=0 ; i < n ;i++)
    {
        if(s > a[i].first)
            s+=a[i].second;
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}