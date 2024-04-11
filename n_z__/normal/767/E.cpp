#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100001],b[100001],h[100001];
struct node
{
	int id;
	int num;
	bool operator<(node x)const
	{
	    return num>x.num;
	}
};
priority_queue<node>q;
signed main()
{
    int n,m;
    int bmdy=0;
    cin>>n>>m;
    for(int x=1;x<=n;x++)
    cin>>a[x];
    for(int x=1;x<=n;x++)
    cin>>b[x];
    for(int x=1;x<=n;x++)
    {
        m-=a[x]%100;
        h[x]=a[x]/100;
        a[x]%=100;
        node y;
        if(a[x]!=0){
            y.id=x;
            y.num=b[x]*(100-a[x]);
            q.push(y);
        }
        while(m<0)
        {
            y=q.top();
            q.pop();
            h[y.id]++;
            m+=100;
            bmdy+=b[y.id]*(100-a[y.id]);
            a[y.id]=0;
        }
    }
    cout<<bmdy<<endl;
    for(int x=1;x<=n;x++)
    cout<<h[x]<<' '<<a[x]<<endl;
}