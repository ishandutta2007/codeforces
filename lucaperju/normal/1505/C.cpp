#include <bits/stdc++.h>

using namespace std;
char v[103];
int a[103];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j;
    cin>>v;
    n=strlen(v);
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=5;
    a[5]=8;
    a[6]=13;
    a[7]=21;
    int s=0;
    int ok=1;
    for(i=2;i<n;++i)
    {
        int vlc=v[i]-'A';
        if (v[i]-'A'!=(v[i-1]-'A'+v[i-2]-'A')%26)
            ok=0;
    }
    if(ok)     cout<<"YES\n";
else
    cout<<"NO\n";
	return 0;
}