#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
char c[1000005];
int n;
string res;
string ans;
string let,rgt;

void deal(int l,int n)
{
    int i=0;
    while(c[i]=='0' && i<n)
    {
        i++;
    }
    for(;i<n;i++)
    {
        res.push_back(c[i]);
    }
}

void calc(int l,int r)
{
    while(c[r-1]=='0' && r>l)
    {
        r--;
    }
    for(int i=l;i<r;i++)
    {
        ans.push_back(c[i]);
    }
}

int main()
{
    scanf("%s",c);
    n=strlen(c);
    int point=n;
    for(int i=0;i<n;i++)
    {
        if(c[i]=='.')
        {
            point=i;
            break;
        }
    }
    deal(0,point);
    calc(point+1,n);
    int e;
    if(res.size())
    {
        e=0;
        let.push_back(res[0]);
        for(int i=1;i<res.size();i++)
        {
            rgt.push_back(res[i]);
            e++;
        }
        for(int i=0;i<ans.size();i++)
        {
            rgt.push_back(ans[i]);
        }
    }
    else
    {
        int i=0;
        e=-1;
        while(ans[i]=='0')
        {
            i++;
            e--;
        }
        let.push_back(ans[i]);
        for(i++;i<ans.size();i++)
        {
            rgt.push_back(ans[i]);
        }
    }
    while(rgt[rgt.size()-1]=='0')
    {
        rgt.pop_back();
    }
    cout<<let[0];
    if(rgt.size())
    {
        cout<<'.';
        printf("%s",rgt.c_str());
    }
    if(e!=0)
    {
        cout<<"E";
        cout<<e<<endl;
    }
    return 0;
}