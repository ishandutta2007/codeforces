#include <bits/stdc++.h>
using namespace std;
int d,s;
bool vis[505][5005];
pair<int,int> pre[505][5005];
int c[505][5005];
string ans;

int main()
{
	int i,j;
	scanf("%d%d",&d,&s);
	queue<pair<int,int> > q;
	q.push(make_pair(0,0));
	vis[0][0]=1;
	pre[0][0]=make_pair(0,0);
	c[0][0]=-1;
	while(!q.empty()){
		auto it = q.front();
		q.pop();
		if(it.first==0&&it.second==s){
			int R=it.first,S=it.second;
			while(!(R==0&&S==0)){
				ans+='0'+c[R][S];
				int RR=pre[R][S].first;
				int SS=pre[R][S].second;
				R=RR;S=SS;
			}
			reverse(ans.begin(),ans.end());
			cout<<ans<<endl;
			return 0;
		}
		for(i=0;i<=9;i++){
			int nr=(it.first*10+i)%d;
			int ns=(it.second+i);
			if(ns<=s&&vis[nr][ns]==0){
				vis[nr][ns]=1;
				c[nr][ns]=i;
				pre[nr][ns]=make_pair(it.first,it.second);
				q.push(make_pair(nr,ns));
			}
		}
	}
	printf("-1\n");
 return 0;
}