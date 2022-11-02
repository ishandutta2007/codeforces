#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        int n,i=1;
        cin>>n;
        int a[n];
        priority_queue<pair<int,int>> pq;
        pq.push({n,0});
        while(!pq.empty())
        {
            pair<int,int> cur = pq.top();
            pq.pop();
            int leng = cur.first;
            int here = -cur.second;
            a[here+(leng-1)/2] = i;
            i++;
            if(leng!=1 && leng!=2)
            {
                pq.push({((leng-1)/2), -here});
                pq.push({(leng)/2, -(here + (leng-1)/2+1)});
            }
            if(leng == 2)
            {
                pq.push({(leng/2), -(here + (leng-1)/2+1)});
            }
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}