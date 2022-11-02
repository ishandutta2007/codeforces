#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n,t,a,b,c,d,maxi,mini;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>c>>d;
        maxi = n * (a+b);
        mini = n * (a-b);
        if(mini > c+d || maxi < c-d)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}