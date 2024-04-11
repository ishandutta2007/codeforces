#include<bits/stdc++.h>
using namespace std;
int n,m,i,k,l;
char a[50000];
int c[500];
int main()
{
    scanf("%s",&a);
    while(a[i]!='\0')
    {
        c[a[i]-'a']++;
        i++;
    }
    for(i=0;i<26;i++)
    {
        if(c[i]%2==1) l++;
    }
    if(l<2) cout<<"First"; else if(l%2==0) cout<<"Second"; else cout<<"First";
    return 0;
}