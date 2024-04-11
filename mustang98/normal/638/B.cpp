#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, cur;
    bool c[26]={0};//    
    bool after[26]={0};//     (    )
    int next[26];// 
    for (int i=0;i<26;i++) next[i]=-1;

    string s;
    cin>>n;
    for (int I=0;I<n;I++)
    {
        cin>>s;
        for (int i=0;i<s.length()-1;i++)
        {
            c[s[i]-97] = true;
            after[s[i+1]-97] = true;
            next[s[i]-97] = s[i+1]-97;
        }
        c[s[s.length()-1]-97]=true;
    }
    while(1)
    {
        for (int i=0;i<26;i++)
        {
            if (c[i] && !after[i]) {cur = i; break;}
            if (i==25) return 0;
        }
        while (cur!=-1)
        {
            c[cur]=false;
            cout<<(char)(cur+97);
            cur = next[cur];
        }
    }
    return 0;
}