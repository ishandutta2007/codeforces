#include<bits/stdc++.h>
using namespace std;

int open=0;

int bad=0;
int main()
{
    int n;
    cin>>n;

    string s;
    cin>>s;

    for(auto k:s)
        if(k=='(')open++;
        else
        {
            if(open)open--;
            else bad++;
        }

    if(open==0&&bad==0)printf("Yes\n");
    else if(open==1&&bad==1)printf("Yes\n");
    else printf("No\n");
    return 0;
}