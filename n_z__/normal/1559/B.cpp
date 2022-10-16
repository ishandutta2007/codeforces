#include<bits/stdc++.h>
using namespace std;
main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        s=" "+s;
        for(int x=1;x<=n;x++)
        {
            if(s[x]=='?')
            {
                if(s[x-1]=='B')s[x]='R';
                else s[x]='B';
                if(x==1){
                    for(int y=2;y<=n;y++)
                    if(s[y]!='?'){
                        if((s[y]=='B')^(y%2))s[x]='R';
                        else s[x]='B';
                        break;
                    }
                }
            }
            cout<<s[x];
        }
        cout<<endl;
    }
}