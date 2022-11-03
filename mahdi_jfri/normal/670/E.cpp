#include <bits/stdc++.h>
using namespace std;
int pairr[500100];
pair<int,int> index[500100];
stack<int>pai;
int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(0);
    int n,m,p;
    cin>>n>>m>>p;
    index[0].first=1;
    index[n+1].first=0;
    index[0].second=n+1;
    index[n+1].second=n;
    string s;
    cin>>s;
    s="c"+s;
    s=s+"x";
    for(int i=1;i<n+1;i++)
    {
        index[i].first=i+1;
        index[i].second=i-1;
    }
    for(int i=1;i<n+1;i++)
    {
        if(!pai.empty() && s[pai.top()]=='(' && s[i] == ')')
        {
            pairr[i]=pai.top();
            pairr[pai.top()]=i;
            pai.pop();
        }
		else pai.push(i);
    }
    string op;
    cin>>op;
    for(int i=0;i<m;i++)
    {
        while((op[i]=='L' || op[i]=='R') && i<m)
            {
                if(op[i]=='L')
                    {p=index[p].second;}
                else
                    {p=index[p].first;}
                //cout<<p<<endl;
                i++;
            }
        if(i<m)
        {
            if(s[p]==')')
            {
                index[index[p].first].second=index[pairr[p]].second;
                index[index[pairr[p]].second].first=index[p].first;
                if(index[p].first==n+1)
                    p=index[pairr[p]].second;
                else
                    p=index[p].first;
            }
            else
            {
                index[index[p].second].first=index[pairr[p]].first;
                index[index[pairr[p]].first].second=index[p].second;
                if(index[pairr[p]].first==n+1)
                    p=index[p].second;
                else
                    p=index[pairr[p]].first;
            }
            //cout<<p<<endl;
        }
    }
    int z=0;
    while(index[z].first!=0)
    {
        if(z!=0)
        cout<<s[z];
        z=index[z].first;
    }
}