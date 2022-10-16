#include<bits/stdc++.h>
using namespace std;
char fa[201];
int ffa(char a)
{
    return fa[a]==a?fa[a]:ffa(fa[a]);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        for(char x='a';x<='z';x++)
        fa[x]=x;
        bitset<201>used;
        int cnt=0;
        for(auto q:s)
        if(fa[q]!=q)cout<<fa[q];
        else{
            for(char x='a';x<='z';x++)
            if(x!=q&&!used[x]&&(fa[x]==x||cnt==25||ffa(x)!=ffa(q)))
            {
                cnt++;
                cout<<x;
                used[x]=1;
                fa[q]=x;
                break;
            }
        }
		cout<<endl;
    }
}