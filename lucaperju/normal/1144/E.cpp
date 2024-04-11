#include <bits/stdc++.h>

using namespace std;
char a[200005],b[200005],rz[200005];
int main()
{
    long long t,n,i,j,mn=100003LL*100003LL,k,mx=0,tot,m,obj,st,cntp=0,cnti=0,s=0,pz;
    cin>>k>>a>>b;
    for(i=k-1;i>=0;--i)
    {
        int vlc=a[i]-'a'+b[i]-'a';
        vlc/=2;
        if(i!=0)
        {
            int vlc1=a[i-1]-'a'+b[i-1]-'a';
            if(vlc1%2==1)
            {
                vlc=(vlc+13)%26;
                if(a[i]-'a'+b[i]-'a'>=26)
                    ++a[i-1];
            }
        }
        rz[i]='a'+vlc;
    }
    for(i=0;i<k;++i)
        cout<<rz[i];
    return 0;
}