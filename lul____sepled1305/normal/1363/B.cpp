/*Nephren is a nice girl.*/
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        string s;
        int i,mini = 1e9;
        cin>>s;
        int n=s.size();
        int quick[n];
        if(s.at(0)=='1')
            quick[0]=1;
        else
            quick[0]=0;
        for(i=1;i<n;i++)
        {
            if(s.at(i)=='1')
                quick[i]=quick[i-1]+1;
            else
                quick[i]=quick[i-1];
        }
        mini = min(quick[n-1],n-quick[n-1]);
        for(i=0;i<n;i++)
        {
            int cur;
            cur = i+1-quick[i]+quick[n-1]-quick[i];
            mini = min(mini,cur);
            cur = quick[i]+(n-i-1)+quick[i]-quick[n-1];
            mini = min(mini,cur);
        }
        cout<<mini<<"\n";
    }
    return 0;
}