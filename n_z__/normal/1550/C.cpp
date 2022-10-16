#include<bits/stdc++.h>
using namespace std;
map<int,int>qq;
int a[200001];
int d(int x,int y)
{
    return abs(a[x]-a[y])+abs(x-y);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int x=1;x<=n;x++)
        cin>>a[x];
        int nowans=0,l=1,r=1;
        while(l<=r&&r<=n)
        {
            nowans+=r-l+1;
            r++;
            qq.erase(qq.begin(),qq.end());
            for(int x=l;x<r;x++)
            for(int y=x+1;y<r;y++)
            if(d(x,y)==d(x,r)+d(y,r)||d(x,y)==abs(d(x,r)-d(y,r)))l=x+1,y=r;
        }
        cout<<nowans<<endl;
    }
    return 0;
}