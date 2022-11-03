#include <bits/stdc++.h>
using namespace std;
// 1-a/(a+x)
// +1 -> +a/(a+x)(a+x+1)
// -1 -> -a/(a+x)(a+x-1)
// f(x)=a/(a+x)(a+x+1)
// f(a,x)>f(a,x+1)
// f(a,x)>=f(a+1,x)>=f(a,x+1) (x+1<=a)
// influenced<=1
const int maxn=200005;
typedef double db;
int n,x[maxn],p[maxn],a[maxn],t,clk[maxn],_;
struct data
{
    db val; int id,clk;
    data(db val=0,int id=0,int clk=0):val(val),id(id),clk(clk) { }
    inline bool operator <(const data &d) const { return val<d.val; }
    inline bool operator >(const data &d) const { return val>d.val; }
};
priority_queue<data> qa;
priority_queue<data,vector<data>,greater<data> > qs;
inline db add1(int i) { return a[i]*(db)p[i]/(a[i]+x[i])/(a[i]+x[i]+1); }
inline db sub1(int i) { return a[i]*(db)p[i]/(a[i]+x[i])/(a[i]+x[i]-1); }
inline void push(int i,int q)
{
    if(x[i]) qs.push(data(sub1(i),i,q));
    if(x[i]<a[i]) qa.push(data(add1(i),i,q));
    clk[i]=q;
}
int main()
{
    int q,i,op;
    double ans=0;
    scanf("%d%d%d",&n,&t,&q);
    for(i=0;i<n;i++) scanf("%d",&p[i]);
    while(!qa.empty()) qa.pop();
    while(!qs.empty()) qs.pop();
    _=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]),x[i]=0;
        qa.push(data(add1(i),i,clk[i]=_));
    }
    for(;t;t--)
    {
        if(qa.empty()) break;
        ans+=qa.top().val,i=qa.top().id;
        qa.pop();
        if((++x[i])<a[i]) qa.push(data(add1(i),i,clk[i]=_));
    }
    for(i=0;i<n;i++)
        if(x[i])
            qs.push(data(sub1(i),i,clk[i]=_));
    while(q--)
    {
        scanf("%d%d",&op,&i),i--;
        ans-=x[i]*(db)p[i]/(a[i]+x[i]);
        if(op==1) a[i]++;
        else if((--a[i])<x[i]) x[i]--,t++;
        ans+=x[i]*(db)p[i]/(a[i]+x[i]);
        clk[i]=++_;
        if(/*op==1 && */x[i])
        {
            while(!qa.empty() && qa.top().clk!=clk[qa.top().id])
                qa.pop();
            if(!qa.empty() && qa.top().val>sub1(i))
            {
                op=qa.top().id;
                ans+=-sub1(i)+qa.top().val,x[op]++,qa.pop(),x[i]--;
                push(op,_);
            }
        }
        /*else */if(/*op==2 && */x[i]<a[i])
        {
            while(!qs.empty() && qs.top().clk!=clk[qs.top().id])
                qs.pop();
            if(!qs.empty() && qs.top().val<add1(i))
            {
                op=qs.top().id;
                ans+=add1(i)-qs.top().val,x[op]--,qs.pop(),x[i]++;
                push(op,_);
            }
        }
        push(i,_);
        while(!qa.empty() && qa.top().clk!=clk[qa.top().id])
            qa.pop();
        if(t && !qa.empty())
        {
            op=qa.top().id,x[op]++,t--,ans+=qa.top().val,qa.pop();
            push(op,++_);
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}