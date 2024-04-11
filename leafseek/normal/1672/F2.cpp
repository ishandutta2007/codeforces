#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5;
struct Vertex
{
	int Inn;
	vector<int> adj;
	int adj_Tot;
};
Vertex vt[MaxN];
int A[MaxN],B[MaxN],cnt[MaxN];
inline void Initalize(const int n)
{
	memset(cnt,0,sizeof(int)*(n+1));
	rep(i,1,n)
		vt[i].Inn=0,vt[i].adj.clear(),vt[i].adj_Tot=0;
}
queue<int> que;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		rep(i,1,n) cin>>A[i],++cnt[A[i]];
		rep(i,1,n) cin>>B[i];
		int u,v,S=0;
		rep(i,1,n) if(cnt[i]>cnt[S]) S=i;
		rep(i,1,n)
		{
			if(A[i]==S||B[i]==S) continue;
			++vt[B[i]].Inn;
			vt[A[i]].adj.push_back(B[i]),++vt[A[i]].adj_Tot;
		}
		rep(i,1,n) if(!vt[i].Inn) que.push(i);
		while(!que.empty())
		{
			u=que.front(),que.pop();
			rep(I,0,vt[u].adj_Tot-1)
			{
				v=vt[u].adj[I];
				if(!(--vt[v].Inn)) que.push(v);
			}
		}
		bool Flag=true;
		rep(i,1,n)
			if(i!=S&&vt[i].Inn) {Flag=false;break;}
		cout<<(Flag?"AC\n":"WA\n"),Initalize(n);
	}
	return 0;
}