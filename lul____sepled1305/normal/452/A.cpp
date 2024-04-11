#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,i,j;
    cin>>n;
    string s;
    cin>>s;
    string ss[8] =  {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
    bool pass = false;
    for(i=0;i<8;i++)
    {
        if(s.size() == ss[i].size())
        {
        for(j=0;j<n;j++)
        {
            if(s.at(j) != '.' && s.at(j)!=ss[i].at(j))
            {
                break;
            }
            if(j == n-1)
                pass = true;
        }
        if(pass)
            break;
        }
    }
    cout<<ss[i];
    return 0;
}