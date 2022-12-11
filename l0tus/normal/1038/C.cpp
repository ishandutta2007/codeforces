#include <bits/stdc++.h>
using namespace std;
int n;
priority_queue<int> A,B;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        A.push(x);
    }
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        B.push(x);
    }
    int cnt = 0;
    long long sA = 0, sB = 0;
    while(!A.empty() || !B.empty())
    {
        int x;
        if(B.empty() || (!A.empty() && A.top()>B.top()))
        {
            x = A.top();
            A.pop();
            if(cnt%2==0) sA += x;
        }
        else
        {
            x = B.top();
            B.pop();
            if(cnt%2==1) sB += x;
        }
        cnt ++;
    }
    cout << sA - sB;
}