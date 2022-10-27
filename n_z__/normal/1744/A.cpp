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
        vector<int>a;
        vector<int>lst(51,-1);
        for(int x=0;x<n;x++)
        {
            int y;
            cin>>y;
            a.push_back(y);
        }
        string s;
        cin>>s;
        for(int x=0;x<n;x++)
        if(lst[a[x]]!=-1&&s[lst[a[x]]]!=s[x]){cout<<"NO"<<endl;goto nxt;}
        else lst[a[x]]=x;
        cout<<"YES"<<endl;
        nxt:;
    }
}