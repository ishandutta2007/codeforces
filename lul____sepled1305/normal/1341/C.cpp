#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int t,n,i;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int arr[n];
        int st,pst=n+1;
        bool success = true;
        for(i=0;i<n;i++)
            cin>>arr[i];
        st = arr[0];
        for(i=1;i<n;i++)
        {
            if(arr[i]!=arr[i-1]+1 && arr[i-1]!=pst-1)
            {
                success = false;
            }
            else if (arr[i]!=arr[i-1]+1)
            {
                pst = st;
                st = arr[i];
            }
        }
        if (success)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}