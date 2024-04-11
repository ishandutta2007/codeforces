#include <bits/stdc++.h>
using namespace std;
priority_queue<int> st,mid;
priority_queue<int, vector<int>, greater<int>> en;
int main()
{
    int n;
    long long ans=1;
    scanf("%d",&n);
    st.push(0);
    en.push(1000000000);
    for(int i=0; i<n; i++)
    {
        char order[10];
        int p;
        scanf("%s",order);
        scanf("%d",&p);
        if(order[1]=='D')
        {
            if(st.top()>p) st.push(p);
            else if(en.top()<p) en.push(p);
            else mid.push(p);
        }
        else
        {
            if(st.top()>p || en.top()<p)
            {
                cout << 0;
                return 0;
            }
            if(p==st.top())
            {
                st.pop();
                while(!mid.empty())
                {
                    int num = mid.top();
                    mid.pop();
                    en.push(num);
                }
                continue;
            }
            if(p==en.top())
            {
                en.pop();
                while(!mid.empty())
                {
                    int num = mid.top();
                    mid.pop();
                    st.push(num);
                }
                continue;
            }
            if(mid.empty())
                {
                    cout << 0;
                    return 0;
                }
            while(mid.top()!=p)
            {
                int num = mid.top();
                mid.pop();
                en.push(num);
                if(mid.empty())
                {
                    cout << 0;
                    return 0;
                }
            }
            mid.pop();
            while(!mid.empty())
            {
                int num = mid.top();
                mid.pop();
                st.push(num);
            }
            ans = (ans*2) % 1000000007;
        }
    }
    ans = (ans*(mid.size()+1)) % 1000000007;
    cout << ans;
}