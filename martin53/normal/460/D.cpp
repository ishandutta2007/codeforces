#include<bits/stdc++.h>
using namespace std;
const int LIM=20;
long long l,r,k;
vector<long long> best;
long long best_x;

vector<long long> now={};

void solve(long long num,long long x)
{
    if(now.size()>k)return;
    if(num>r)
    {
        if(best_x>x&&now.size())
        {
            best_x=x;
            best=now;
        }
        return;
    }

    solve(num+1,x);
    now.push_back(num);
    solve(num+1,x^num);
    now.pop_back();
}
void run(int bit,long long a,long long b,long long c)
{
    //cout<<"run "<<bit<<" "<<a<<" "<<b<<" "<<c<<endl;
    if(bit<0)
    {
        if(l<=a&&a<=r&&l<=b&&b<=r&&l<=c&&c<=r)
        {
            cout<<0<<endl;
            cout<<3<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
            exit(0);
        }
        return;
    }

    if(a>r||b>r||c>r)return;
    if(a+2*(1LL<<bit)-1<l||b+2*(1LL<<bit)-1<l||c+2*(1LL<<bit)-1<l)return;

    run(bit-1,a,b,c);
    run(bit-1,a+(1LL<<bit),b+(1LL<<bit),c);
    run(bit-1,a+(1LL<<bit),b,c+(1LL<<bit));
    run(bit-1,a,b+(1LL<<bit),c+(1LL<<bit));
}
vector<long long> solve()
{
    best={l};
    best_x=l;

    if(r-l<=15)
    {
        solve(l,0);
        return best;
    }

    if(k==1)return best;
    if(k==2)
    {
        while(l%2)l++;
        best={l,l+1};
        return best;
    }

    if(k>=4)
    {
        while(l%4)l++;
        best={l,l+1,l+2,l+3};
        return best;
    }

    //k=3
    run(39,0,0,0);

    while(l%2)l++;
    best={l,l+1};
    return best;
}
int main()
{
cin>>l>>r>>k;

vector<long long> output=solve();

long long x=0;
for(auto p:output)x=x^p;

cout<<x<<endl;
cout<<output.size()<<endl;
for(auto p:output)cout<<p<<" ";cout<<endl;
return 0;
}