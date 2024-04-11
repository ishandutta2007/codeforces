#include<bits/stdc++.h>
#define maxn 500020
using namespace std;
int n,m,ls[maxn*20],rs[maxn*20],s[maxn*20],num,rt[maxn];
 int build(int l, int r)
{
	int now = ++ num;
	int mid=(l+r)/2;
	if (l < r){
		ls[now] = build(l, mid);
		rs[now] = build(mid+1, r);
	}
	return now;
}
 
int update(int pre,int l,int r,int id){
	int now=++num;
	ls[now]=ls[pre],rs[now]=rs[pre],s[now]=s[pre]+1;
 
	int mid=l+r>>1;
	if(l<r)
	{if(id<=mid)
        ls[now]=update(ls[pre],l,mid,id);
	else
	rs[now]=update(rs[pre],mid+1,r,id);
	}
	return now;
}
int query(int x,int y,int l,int r,int k){
	if(l==r){
		if(s[y]-s[x]>k)return s[y]-s[x];
		else return 0;
	}
	int mid=l+r>>1;
	if(s[ls[y]]-s[ls[x]]>k)return query(ls[x],ls[y],l,mid,k);
	else if(s[rs[y]]-s[rs[x]]>k)return query(rs[x],rs[y],mid+1,r,k);
	else return 0;
}
 
int main()
{
	cin>>n>>m;
	rt[0]=build(1,m);
	for(int x,i=1;i<=n;i++){
		cin>>x;
		rt[i]=update(rt[i-1],1,n,x);
	}
	int a,b;
	while(m--){
		scanf("%d%d",&a,&b);
		int u=query(rt[a-1],rt[b],1,n,(b-a+2)/2);
    	if (u>(b-a+2)/2)
		{
			cout<<u-(b-a+1-u+1)+1<<endl;
		} else puts("1");
	}
	return 0;
}