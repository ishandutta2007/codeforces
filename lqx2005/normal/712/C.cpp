#include<bits/stdc++.h>
using namespace std;
void v(int &a,int &b,int &c)
{
    int d;
    if(c<a)
    {
        swap(a,c);
    }
    if(c<b)
    {
        swap(b,c);
    }
    if(a>b)
    {
        swap(a,b);
    }
}
string s;
int main()
{
    int x,y,a[3],ans=0;
    cin>>x>>y;
    a[0]=a[1]=a[2]=y;
    while(a[0]!=x||a[1]!=x||a[2]!=x)
    {
        v(a[0],a[1],a[2]);
        int now=a[0];
        a[0]=a[1]+a[2]-1;
        if(a[0]>x)
        {
            a[0]=x;
        }
        ans++;	
    }
    cout<<ans<<endl;
}