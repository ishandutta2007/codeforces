#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
string s[]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main()
{
    int len;
    string a;
    cin>>len>>a;
    for(int i=0;i<8;i++)
    {
        if(len==s[i].length())
        {
            int f=1;
            for(int j=0;j<len;j++)
            {
                if(a[j]!='.' && a[j]!=s[i][j]) f=0;
            }
            if(f)
            {
                cout<<s[i]<<endl;
                return 0;
            }
        }
    }
}