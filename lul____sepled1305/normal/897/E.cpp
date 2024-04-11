/**Chtholly Best Girl**/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<long long,long long>;
const long long INF = 1e18+7;
const long long N = 1e5+7;
const long long MOD = 1e9+7;
long long n,m,seed,v_max,i,j,k;
long long a[N];
long long op,l,r,x,y;

long long plusi(long long a, long long b, long long mo)
{
    long long cur = (0LL+a+b)%mo;
    return cur;
}
long long multi(long long a,long long b, long long mo)
{
    a%=mo, b%=mo;
    long long cur = (1LL*a*b)%mo;
    return cur;
}
long long power(long long base, long long pow,long long mo)
{
    if(pow==0LL)
        return 1LL;
    if(pow==1LL)
    {
        base%=mo;
        return base;
    }

    long long cur = power(base,pow/2,mo);
    cur = multi(cur,cur,mo);
    if(pow%2)
        cur = multi(cur,base,mo);
    return cur;
}

long long rnd()
{
    long long cur = seed;
    seed = ((seed*7)+13) % MOD;
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>seed>>v_max;
    for(i=1; i<=n; i++)
        a[i] = rnd()%v_max +1;
    queue<pii> prv,pq;
    for(i=1; i<=n; i++)
    {
        pii u = {i,i};
        pq.push(u);
    }
    for(i=0; i<m; i++)
    {
        op = rnd()%4 + 1;
        l = rnd()%n + 1;
        r = rnd()%n + 1;

        if(l>r)
            swap(l,r);

        if(op==3)
            x = rnd() % (r-l+1) +1;
        else
            x = rnd() % v_max +1;

        if(op == 4)
            y = rnd() % v_max +1;

        //cout<<op<<" "<<l<<" "<<r<<" "<<x<<" ? "<<y<<"\n";

        /**Painful bashing part**/

        if(op==1)
        {
            while(!pq.empty())
            {
                pii cur = pq.front();
                pq.pop();
                long long q = cur.first;
                long long w = cur.second;
                if(q == l && w == r)
                    a[q]+=x;
                if(q==l && w<r)
                    a[q]+=x;
                if(q==l && w>r)
                    prv.push({q,r}), a[r+1] = a[q], a[q]+=x, q = r+1;
                if(q>l && w==r)
                    a[q]+=x;
                if(q>l && w>r && q<=r)
                    prv.push({q,r}), a[r+1] = a[q], a[q]+=x, q = r+1;
                if(q<l && w==r)
                    prv.push({q,l-1}), a[l] = a[q]+x, q = l;
                if(q<l && w<r && w>=l)
                    prv.push({q,l-1}), a[l] = a[q]+x, q = l;
                if(q>l && w<r)
                    a[q]+=x;
                if(q<l && w>r)
                {
                    prv.push({q,l-1});
                    prv.push({r+1,w});
                    a[r+1] = a[q];
                    a[l] = a[q]+x;
                    q = l;
                    w = r;
                }
                prv.push({q,w});
            }
        }
        if(op==2)
        {
            while(!pq.empty())
            {
                pii cur = pq.front();
                pq.pop();
                long long q = cur.first;
                long long w = cur.second;
                if(q==l && w>r)
                    prv.push({r+1,w}), a[r+1] = a[q];
                if(q<l && w==r)
                    prv.push({q,l-1});
                if(q<l && w>r)
                {
                    prv.push({q,l-1});
                    prv.push({r+1,w});
                    a[r+1] = a[q];
                }
                if(q<l && w<r && w>=l)
                    prv.push({q,l-1});
                if(q>l && w>r && q<=r)
                    prv.push({r+1,w}), a[r+1] = a[q];
                if(w<l || q>r)
                    prv.push({q,w});
            }
            prv.push({l,r});
            a[l] = x;
        }
        if(op==3)
        {
            priority_queue<pii> ans;
            while(!pq.empty())
            {
                pii cur = pq.front();
                pq.pop();
                long long q = cur.first;
                long long w = cur.second;
                if(q == l && w == r)
                    ans.push({-a[q],r-l+1});
                if(q==l && w<r)
                    ans.push({-a[q],w-l+1});
                if(q==l && w>r)
                    ans.push({-a[q],r-l+1});
                if(q>l && w==r)
                    ans.push({-a[q],r-q+1});
                if(q<l && w==r)
                    ans.push({-a[q],r-l+1});
                if(q>l && w>r && q<=r)
                    ans.push({-a[q],r-q+1});
                if(q>l && w<r)
                    ans.push({-a[q],w-q+1});
                if(q<l && w<r && w>=l)
                    ans.push({-a[q],w-l+1});
                if(q<l && w>r)
                    ans.push({-a[q],r-l+1});
                prv.push({q,w});
            }
            long long here = 0;
            long long prin = 1e18+7;
            while(here < x)
            {
                here+=ans.top().second;
                prin = -ans.top().first;
                ans.pop();
            }
            cout<<prin<<"\n";
        }
        if(op==4)
        {
            long long ans = 0;
            while(!pq.empty())
            {
                pii cur = pq.front();
                pq.pop();
                long long q = cur.first;
                long long w = cur.second;
                if(q == l && w == r)
                    ans = multi(r-l+1,power(a[q],x,y),y);
                if(q==l && w<r)
                    ans = plusi(ans,multi(w-q+1,power(a[q],x,y),y),y);
                if(q==l && w>r)
                    ans = multi(r-l+1,power(a[q],x,y),y);
                if(q>l && w==r)
                    ans = plusi(ans,multi(w-q+1,power(a[q],x,y),y),y);
                if(q<l && w==r)
                    ans = multi(r-l+1,power(a[q],x,y),y);
                if(q<l && w<r && w>=l)
                    ans = plusi(ans,multi(w-l+1,power(a[q],x,y),y),y);
                if(q>l && w<r)
                    ans = plusi(ans,multi(w-q+1,power(a[q],x,y),y),y);
                if(q>l && w>r && q<=r)
                    ans = plusi(ans,multi(r-q+1,power(a[q],x,y),y),y);
                if(q<l && w>r)
                    ans = multi(r-l+1,power(a[q],x,y),y);
                prv.push({q,w});
                //cout<<q<<" "<<w<<" "<<ans<<" REF\n";
            }
            cout<<ans<<"\n";
        }
        while(!prv.empty())
        {
            pq.push(prv.front());
            //cout<<prv.top().first<<" "<<prv.top().second<<" "<<a[prv.top().first]<<"\n";
            prv.pop();
        }
    }
    return 0;
}