#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int ct[26]={0};
    string s;
    cin>>s;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        ct[s[i]-'a']++;
        if(ct[s[i]-'a']>k)
        {
            flag=1;
            break;
        }
    }
    if(flag==0)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}