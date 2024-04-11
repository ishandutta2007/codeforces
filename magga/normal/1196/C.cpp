#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int max=100000;
    long long int r;cin>>r;
    long long int n,w,e,s;
    n=max;e=max;w=-1*max;s=-1*max;
    for(long long int i=0;i<r;i++)
    {
        long long int x,y,f1,f2,f3,f4;
        cin>>y>>x>>f1>>f2>>f3>>f4;
    //s e n w
        if(f1==0 && s<y)
        {
            s=y;
        }
        if(f2==0 && e>x)
        {
            e=x;
        }
        if(f3==0 && n>y)
        {
            n=y;
        }
        if(f4==0 && w<x)
        {
            w=x;
        }
        //cout<<s<<" "<<e<<" "<<n<<" "<<w<<endl; 
    }
    if(n>=s && e>=w)
    {
        cout<<1<<" "<<n<<" "<<e<<endl;    
    }    
    else
    {
        cout<<0<<endl;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}