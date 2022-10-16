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
        vector<int>v(n+1),e;
        map<int,int>q,w;
        for(int x=1;x<=n;x++)
        cin>>v[x],q[v[x]]++;
        int a=0;
        for(int x=1;x<=n;x++)
        {
            w[v[x]]++;
            q[v[x]]--;
            while(w[a]>0)a++;
            if(!q[a])e.push_back(a),a=0,w.clear();
        }
        cout<<e.size()<<endl;
        for(auto r:e)cout<<r<<' ';
        cout<<endl;
    }
}