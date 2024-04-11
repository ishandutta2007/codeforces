#include <bits/stdc++.h>

using namespace std;
char a[1000006],b[1000006];
int main()
{
    int t,la,lb;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        la=strlen(a);
        lb=strlen(b);
        if(lb<la)
        {
            cout<<"NO\n";
            continue;
        }
        int i=0,j=0,ok=1;
        while(i<la || j<lb)
        {
            if(j>=lb || i>=la)
            {
                cout<<"NO\n";
                ok=0;
                break;
            }
            if(a[i]!=b[j])
            {
                cout<<"NO\n";
                ok=0;
                break;
            }
            int cnta=0,cntb=0;
            while(i<la && a[i]==b[j])
            {
                ++i;
                ++cnta;
            }
            while(j<lb && b[j]==a[i-1])
            {
                ++j;
                ++cntb;
            }
            if(cnta>cntb)
            {
                cout<<"NO\n";
                ok=0;
                break;
            }
        }
        if(ok)
            cout<<"YES\n";
    }
    return 0;
}