#include <iostream>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

struct request
{
    ll t, d, num;
};

queue <request> q;



int main()
{
    ll n,b,fin=0/*   */, cur=0;
    ll t[200001], d[200001];
    request r;
    cin>>n>>b;
    ll res[200001];//={0};
    for (int i=0;i<n;i++) cin>>t[i]>>d[i];
    while (cur<n)
    {
        while (fin && fin<=t[cur])// ,    
        {
            res[q.front().num] = fin;
            q.pop();
            if (q.empty()) {fin=0;break;}
            fin = max(fin, q.front().t)+q.front().d;//  
        }

        //  
        if (q.size()==b+1)
        {
            res[cur]=-1;
            cur++;
        }
        else
        {
            r.num = cur;
            r.d = d[cur];
            r.t = t[cur];
            if (q.empty()) {fin = t[cur]+d[cur];}
            q.push(r);
            cur++;
        }
    }
    while (!q.empty())// ,    
    {
        res[q.front().num] = fin;
        q.pop();
        if (q.empty()) break;
        fin = max(fin, q.front().t)+q.front().d;//  
    }


    for (int i=0;i<n;i++) cout<<res[i]<<' ';
    return 0;
}