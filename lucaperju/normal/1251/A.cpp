#include <bits/stdc++.h>

using namespace std;
string s;
char v[27];
int main()
{
    int t,tst,n;
    cin>>t;
    int cont=0;
    char ch;
    for(tst=1;tst<=t;tst++)
    {
        cin>>s;
        n=s.size();
        ch=s[0];
        cont=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]==ch)
                cont++;
            else
            {
                if(cont%2==1)
                    v[ch-'a']=1;
                ch=s[i];
                cont=1;
            }
        }
        if(cont%2==1)
            v[ch-'a']=1;
        for(int i=0;i<26;i++)
        {
            if(v[i]==1)
                {
                    char cc='a'+i;
                    cout<<cc;
                }
        }
        cout<<'\n';
        memset(v,0,26);
    }
    return 0;
}