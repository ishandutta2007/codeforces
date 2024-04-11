#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool vis[1<<17];
long long f(const vector<int>&A)
{
	vector<pair<int,int> >st(A.size());
	for(int i=0;i<A.size();i++)
	{
		st[i]=make_pair(A[i],i);
		vis[i]=false;
	}
	sort(st.begin(),st.end());
	long long ans=0;
	for(int i=A.size();i--;)
	{
		int id=st[i].second;
		ans+=st[i].first;
		if(id>0&&vis[id-1])ans-=st[i].first;
		if(id+1<A.size()&&vis[id+1])ans-=st[i].first;
		vis[id]=true;
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		vector<int>A(N);
		for(int i=0;i<N;i++)cin>>A[i];
		vector<int>B=A;
		sort(B.begin(),B.end());
		cout<<(f(A)<=f(B)?"YES\n":"NO\n");
	}
}