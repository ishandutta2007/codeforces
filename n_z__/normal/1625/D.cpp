
#include<bits/stdc++.h>
using namespace std;
const int maxn=300005;
vector<int> G[maxn],ans;
map<int,int> ap;
int tot,ch[maxn*30][2],num,a[maxn],n,k;
void insert(int x)
{
    int now=0;
    for(int i=30;i>=0;i--)
	{
        int t=(x>>i)&1;
        if(!ch[now][t]) ch[now][t]=++num;
        now=ch[now][t];
    }
}
int query(int x)
{
    int ret=0,now=0;
    for(int i=30;i>=0;i--)
	{
        int t=(x>>i)&1;
        if(ch[now][t^1]) ret|=(1<<i),now=ch[now][t^1];
        else now=ch[now][t];
    }
    return ret;
}
void init()
{
	for(int i=0;i<=num;i++)
		ch[i][0]=ch[i][1]=0;
	num=0;
}
int main()
{
    cin>>n>>k;
    if(k==0)
	{cout<<n<<endl;for(int i=1;i<=n;i++)cout<<i<<" ";return 0;}
    int bit=31;
    for(int i=30;i>=0;i--)if((k>>i)==0)bit=i;
    for(int i=1;i<=n;i++)
	{
        cin>>a[i];
        if(!ap[a[i]>>bit])ap[a[i]>>bit]=++tot;
        G[ap[a[i]>>bit]].push_back(i);
    }
    for(int i=1;i<=tot;i++)
	{
		init();
        int to=-1;
        for(auto x : G[i])
		{
            if(num)if(query(a[x])>=k){to=x;break;}
            insert(a[x]);
        }
        if(to==-1)ans.push_back(G[i][0]);
        else
            for(auto x : G[i]) 
				if(x!=to&&(a[to]^a[x])>=k)
				{ans.push_back(x),ans.push_back(to);break;}
    }
    if(ans.size()==1)return puts("-1"),0;
    printf("%d\n",ans.size());
    for(auto v : ans)printf("%d ",v);
}