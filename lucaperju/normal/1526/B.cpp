#include <bits/stdc++.h>
using namespace std;
int v[55];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,i;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        while(n%11)
        {
            if(n>=111)
                n-=111;
            else
                break;
        }
        if(n%11)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
	return 0;
}