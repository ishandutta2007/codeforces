#include<bits/stdc++.h>
using namespace std;
main()
{
    int n, p[101];
    string c;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i];
    bool ok=true;
    getline(cin, c);
    for(int i=1; i<=n; i++)
    {
        getline(cin, c);
        int t=0;
        for(int j=0; j<=c.size()-1; j++)
        {
            if(c[j]=='a'||c[j]=='e'||c[j]=='i'||c[j]=='o'||c[j]=='u'||c[j]=='y') t++;
        }
        if(t!=p[i]){
            ok=false;
        }
    }
    if(ok==true) cout<<"YES";
    else cout<<"NO";

}