#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n;
string str[11]={"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"},a;
int main()
{
    cin>>n>>a;
    for(int i=0;i<8;i++)
    {
        if(n!=str[i].length()) continue;
        else
        {
            bool p=true;
            for(int j=0;j<n;j++)
                if(a[j]!='.'&&a[j]!=str[i][j]) {p=false;break;}
            if(!p) continue;
        }
        {cout<<str[i]<<endl;return 0;}
    }
    return 0;
}