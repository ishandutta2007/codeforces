#include <bits/stdc++.h>
using namespace std;
typedef struct Pii
{
    int first,second;
    bool operator < (const struct Pii &a) const
    {
        return first > a.first;
    }
}pii;
struct Break
{
    int idx,num;
    bool operator < (struct Break a)
    {
        return num < a.num;
    }
}str[200010];
priority_queue<pii> V;
int main()
{
    int n,m,d,day[200010];
    cin >> n >> m >> d;
    for(int i=0; i<n; i++)
    {
        cin >> str[i].num;
        str[i].idx=i;
    }
    sort(str,str+n);
    int cur=0,sz=1;
    pii x = {str[0].num,1};
    V.push(x);
    day[str[0].idx] = 1;
    for(int i=1; i<n; i++)
    {
        pii x = V.top();
        if(x.first + d < str[i].num)
        {

            day[str[i].idx] = x.second;
            V.pop();
            pii k = {str[i].num,x.second};
            V.push(k);
        }
        else
        {
            pii k = {str[i].num,++sz};
            V.push(k);
            day[str[i].idx] = sz;
        }
    }
    cout <<  sz << '\n';
    for(int i=0; i<n; i++) cout << day[i] << ' ';
}