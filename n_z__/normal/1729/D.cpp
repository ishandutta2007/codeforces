#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        priority_queue<int>a;
        priority_queue<int,vector<int>,greater<>>b;
        vector<int>q(n+1);
        for(int x=1;x<=n;x++)
        cin>>q[x];
        for(int x=1;x<=n;x++)
        {
            int w;
            cin>>w;
            if(w-q[x]<0)a.push(w-q[x]);
            else b.push(w-q[x]);
        }
        int ans=0;
        while(!a.empty()&&!b.empty())
        {
            int qwq=a.top(),qwq2=b.top();
            if(qwq+qwq2>=0)ans++,a.pop(),b.pop();
            else if(b.size()>=2)ans++,b.pop(),b.pop();
            else break;
        }
        cout<<ans+b.size()/2<<endl;
    }
}