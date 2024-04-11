#include<bits/stdc++.h>
using namespace std;
long long k,i,j,ans = 1;
long long a[10]={1,1,1,1,1,1,1,1,1,1};
string s = "codeforces";

long long fast()
{
    int i;
    long long cur=1;
    for(i=0;i<10;i++)
        cur*=a[i];
    return cur;
}

int main()
{
    cin>>k;
    while(fast()<k)
    {
        int mini = a[0], index  = 0;
        for(j=0;j<10;j++)
        {
            if(a[j]<mini)
            {
                mini = a[j];
                index = j;
            }
        }
        a[index]++;
        ans++;
    }
    for(j=0;j<10;j++)
    {
        while(a[j]--)
        {
            cout<<s.at(j);
        }
    }
}