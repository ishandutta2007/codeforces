#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1e5+42;
int n,p,q;
pair<int,int> inp[nmax],active[nmax];
long long area(pair<int,int> a,pair<int,int> b,pair<int,int> c)
{
    long long x1=b.first-a.first,y1=b.second-a.second;
    long long x2=b.first-c.first,y2=b.second-c.second;
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    return x1*y2-x2*y1;
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
    long long s=area(a,{0,0},b);
    if(s)return s<0;
    return a.first<b.first;
}
stack< pair<int,int> > s;
int n_;
bool need(pair<int,int> c)
{
    pair<int,int> b=s.top();
    s.pop();
    pair<int,int> a=s.top();
    s.push(b);
    if(area(a,b,c)<=0)return 1;
    return 0;
}
double solve(int a,int c,int b,int d)
{
    double t1=1.0*(p*d-q*b)/(a*d-b*c);
    double t2=1.0*(p*c-q*a)/(b*c-a*d);
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    //cout<<t1<<" "<<t2<<endl;
    assert(t1>=0&&t2>=0);
    return t1+t2;
}
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>p>>q;
double ans=max(p,q);
for(int i=1;i<=n;i++)
{
    cin>>inp[i].first>>inp[i].second;
    ans=min(ans,max(1.0*p/inp[i].first,1.0*q/inp[i].second));
}

sort(inp+1,inp+n+1,cmp);
/*
for(int i=1;i<=n;i++)
    cout<<inp[i].first<<" "<<inp[i].second<<endl;
*/
s.push(inp[1]);
for(int i=2;i<=n;i++)
{
    while(s.size()>1&&need(inp[i]))s.pop();
    s.push(inp[i]);
}

n_=s.size();
for(int i=1;i<=n_;i++){active[i]=s.top();s.pop();}
/*
cout<<endl;
for(int i=1;i<=n_;i++)cout<<active[i].first<<" "<<active[i].second<<endl;
*/
for(int i=2;i<=n_;i++)
    if(active[i].first*active[i-1].second!=active[i].second*active[i-1].first)
    {
        //cout<<area(active[i-1],{0,0},active[i])<<endl;
        if(area(active[i-1],{0,0},{p,q})>0&&area({p,q},{0,0},active[i])>0)
        {
            //cout<<":)"<<endl;
            ans=min(ans,solve(active[i-1].first,active[i-1].second,active[i].first,active[i].second));
        }
    }
printf("%.18f\n",ans);
return 0;
}