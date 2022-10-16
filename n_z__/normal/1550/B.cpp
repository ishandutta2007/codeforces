#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        s=' '+s;
        if(b>=0)cout<<(a+b)*n<<endl;
        else {
            int o=1;
            for(int x=1;x<n;x++)
            if(s[x+1]!=s[x])o++;
            cout<<a*n+(1+o/2)*b<<endl;
        }
    }
    return 0;
}