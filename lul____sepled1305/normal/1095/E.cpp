#include<bits/stdc++.h>
using namespace std;
int n,i,bad,wow,counti,last=-1,bad_indice=-1,moom=1;
char a[1000010];
stack<int> h;
stack<int> m;
int main()
{
    cin>>n;
    scanf("%s",&a);
    for(i=0;i<n;i++)
    {
        if(a[i]=='(')
        {
            h.push(1);
        }
        else if (!h.empty())
        {
            h.pop();
        }
        else if(bad==0)
        {
            bad=1;
            h.push(1);
            bad_indice=i;
        }
        else
        {
            bad++;
            h.push(1);
        }
        if(h.size()==1)
            {
                last=i;
            }
    }
    if(h.size()==2 && bad==0)
    {
        for(i=last+1;i<n;i++)
        {
            if(a[i]=='(')
            {
                counti++;
            }
        }
    }
    else if(bad_indice>-1 && bad==1 && h.size()==0)
    {
        for(i=0;i<=bad_indice;i++)
        {
            if(a[i]==')')
            {
                counti++;
            }
        }
    }
    //cout<<bad_indice;
    cout<<counti;
    return 0;
}