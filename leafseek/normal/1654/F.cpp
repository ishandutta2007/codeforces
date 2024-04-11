#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=18+5,MaxFull=((1<<18)|5),Sigma=26,Error=(-1);
int *arr[MaxN],arr_Load[MaxFull<<1],*arr_This=arr_Load;
queue<int> que_Ext[Sigma],que[2][MaxFull];
char str[MaxFull],str_Ans[MaxFull];
inline int Dfs(const int n,const int I,const int x)
{
	if(I==n) return x;
	int y[2];
	rep(O,0,1)
	{
		rep(i,0,(1<<(n-I-1))-1)
			que[0][arr[I][i<<1|!O]].push(i);
		rep(i,0,(1<<(n-I))-1)
			while(!que[0][i].empty())
			{
				const int u=que[0][i].front();
				que[0][i].pop();
				que[1][arr[I][u<<1|O]].push(u);
			}
		int cnt=(-1);
		rep(i,0,(1<<(n-I))-1)
		{
			int v=Error;
			while(!que[1][i].empty())
			{
				const int u=que[1][i].front();
				que[1][i].pop();
				if((v==Error)||(arr[I][u<<1|!O]!=arr[I][v<<1|!O])) ++cnt;
				arr[I+1][u]=cnt,v=u;
			}
		}
		y[O]=Dfs(n,I+1,x|(O<<I));
	}
	bool O=0;
	rep(i,0,(1<<(n-I))-1)
	{
		if(arr[I][i^(y[0]>>I)]<arr[I][i^(y[1]>>I)])
			break;
		if(arr[I][i^(y[0]>>I)]>arr[I][i^(y[1]>>I)])
			{O=1;break;}
	}
	return y[O];
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n>>str;
	rep(i,0,n)
		arr[i]=arr_This,arr_This+=(1<<(n-i));
	rep(i,0,(1<<n)-1) que_Ext[str[i]-'a'].push(i);
	int cnt=(-1);
	rep(i,0,Sigma-1)
	{
		if(que_Ext[i].empty()) continue;
		++cnt;
		while(!que_Ext[i].empty())
			arr[0][que_Ext[i].front()]=cnt,que_Ext[i].pop();
	}
	const int x=Dfs(n,0,0);
	rep(i,0,(1<<n)-1) str_Ans[i]=str[i^x];
	cout<<str_Ans<<'\n';
	return 0;
}