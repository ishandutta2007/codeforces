#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 5e5+10;
bool d[N];

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int q;
    cin>>q;
    int pointer1 = 1,pointer2 = 1;
    priority_queue<pii> pq;
    while(q--)
    {
        int cs;
        cin>>cs;
        if(cs == 1)
        {
            int money;
            cin>>money;
            pq.push({money,-pointer1});
            pointer1++;
        }
        else if(cs == 2)
        {
            while(d[pointer2])
                pointer2++;
            d[pointer2] = true;
            cout<<pointer2<<' ';
            pointer2++;
        }
        else
        {
            pii cur = pq.top();
            pq.pop();
            while(d[-cur.second])
            {
                cur = pq.top();
                pq.pop();
            }
            d[-cur.second] = true;
            cout<<-cur.second<<' ';
        }
    }
}