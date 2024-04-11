#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        s=' '+s;
        string ans;
        for(int qwq=n;qwq>=1;qwq--)
        {
            if(s[qwq]=='0'){ans=(char)(s[qwq-1]-'0'+10*(s[qwq-2]-'0')+'a'-1)+ans;qwq-=2;}
            else ans=(char)(s[qwq]-'0'+'a'-1)+ans;
        }
        cout<<ans<<endl;
    }
}