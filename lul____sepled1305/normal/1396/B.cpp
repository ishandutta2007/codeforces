#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,sum =0;
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        priority_queue<int> pq;
        for(i=0;i<n;i++)
            pq.push(a[i]);
        int turn = 0,hold = -1;
        while(!pq.empty())
        {
            int cur = pq.top();
            cur--;
            pq.pop();
            if(hold!=-1)
            {
                pq.push(hold);
                hold = -1;
            }
            if(pq.size() == 0)
            {
                turn++;
                break;
            }
            else
            {
                turn++;
                if(cur != 0)
                    hold = cur;
            }
        }
        if(turn%2)
            cout<<"T\n";
        else
            cout<<"HL\n";
    }
    return 0;
}