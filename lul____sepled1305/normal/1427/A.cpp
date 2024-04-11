/**Ogiso Setsuna**/
#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        int a[n];
        int sum = 0;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum == 0)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            if(sum > 0)
            {
                sort(a,a+n,greater<int>());
            }
            else
                sort(a,a+n);
            for(i=0;i<n;i++)
                cout<<a[i]<<' ';
            cout<<endl;
        }
    }
    return 0;
}