#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
const int mod=1e4+7;
string s;
ll _max;
int k,n;
/*
void print(deque<int>dq)
{
    for(int i=0;i<dq.size();i++)
        cout<<s[dq[i]]<<" ";
    cout<< endl;
}
*/
ll hal(char c)
{
    deque<int>dq;
    _max=0;
    int x=0;
    for(int i=0; i < n; i++)
    {
        if( s[i] == c || x < k )
        {
            dq.push_back(i);
            if(s[i]!=c)
                x++;
            _max=max((ll)dq.size(),_max);
        }
        if(x == k)
        {
            while(s[++i] == c && i < n)
            {
                dq.push_back(i);
                _max=max((ll)dq.size(),_max);
            }
            i--;
            while(!dq.empty() && s[dq.front()] == c)
                dq.pop_front();
            if(!dq.empty())
            {
                x--;
                dq.pop_front();
            }
        }
    }
    return _max;
}
int main()
{
    cin >> n >> k;
    cin >> s;
    cout << max(hal('a'),hal('b'));
}