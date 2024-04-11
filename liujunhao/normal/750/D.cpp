#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
typedef unsigned uint;
typedef unsigned long long uLL;
const double pi=acos(-1);
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
//
#define MAXN 30
bool vis[1000][1000];
int n,t[MAXN+10],dir[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}},ans;
vector<pair<pii,int>>q1,q2;
int main()
{
	Read(n);
	int i;
	for(i=1;i<=n;i++)
		Read(t[i]);
	q1.push_back(pair<pii,int>(pii(500,500),0));
	for(i=0;i<t[1];i++)
		vis[500+i][500]=1;
	for(i=2;i<=30;i++){
		q2.clear();
		for(auto j=q1.begin();j<q1.end();j++){
			pii now=j->first;
			int d=(j->second+1)&7;
			for(int k=0;k<t[i];k++){
				now.first+=dir[d][0];
				now.second+=dir[d][1];
				vis[now.first][now.second]=1;
			}
			q2.push_back(make_pair(now,d));
			now=j->first;
			d=(j->second+7)&7;
			for(int k=0;k<t[i];k++){
				now.first+=dir[d][0];
				now.second+=dir[d][1];
				vis[now.first][now.second]=1;
			}
			q2.push_back(make_pair(now,d));
		}
		sort(q2.begin(),q2.end());
		q2.erase(unique(q2.begin(),q2.end()),q2.end());
		q1.swap(q2);
	}
	for(int i=0;i<1000;i++)
		for(int j=0;j<1000;j++)
			ans+=vis[i][j];
	printf("%d\n",ans);
}