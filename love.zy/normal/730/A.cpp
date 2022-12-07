#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n,mx,mn=10005;
int dat[105],delta[105];
int sum_delta,dmx,dmn;
char lst[100005][105];
int ans;
char team[105];

void calc_para()
{
	sum_delta=0;
	dmx=0;dmn=10005;
	for (int i=1;i<=n;i++) 
	{
		delta[i]=dat[i]-mn;
		sum_delta+=delta[i];
		dmx=max(dmx,delta[i]);
		dmn=min(dmn,delta[i]);
	}
}
void team_clear()
{
	for (int i=1;i<=n;i++) team[i]='0';team[n+1]=0;
}
void brute_go()
{
	printf("0\n%d\n",mx*n);
	team_clear();
	for (int i=1;i<=n;i++)
	{
		team[i==1?n:i-1]='0';
		team[i]='1';
		team[i==n?1:i+1]='1';
		for (int j=1;j<=mx;j++) printf("%s\n",team+1);		
	}
}
int ths,nxt;
struct player
{
	int res,pos;
	bool operator < (const player &b) const {return res<b.res;} 
}A,B;
priority_queue<player> pq;
bool find_team()
{
	if (pq.empty())return 0;
	A=pq.top();pq.pop();B=pq.top();pq.pop();
	ths=A.pos;nxt=B.pos;
	A.res--;B.res--;
	if (A.res) pq.push(A);
	if (B.res) pq.push(B);
	return 1;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&dat[i]);
		mx=max(mx,dat[i]);mn=min(mn,dat[i]);
	}
	if (n==2&&dat[1]!=dat[2]) {brute_go();return 0;}
	calc_para();
	while(mn>0&&dmx*2>sum_delta) {mn--;calc_para();}
	if (mn==0) {brute_go();return 0;}
	if (sum_delta&1)
	{
		int delta_not_zero=0;
		for (int i=1;i<=n;i++) if (delta[i]) delta_not_zero++;
		if (delta_not_zero<3)
		{
			if (mn==0) {brute_go();return 0;}
			mn--;
			calc_para();
		}
		if (sum_delta&1)
		{
			int a,b,c;delta_not_zero=0;
			for (int i=1;i<=n;i++)
			{
				if (delta[i]==0) continue;
				if (delta_not_zero==0) {a=i;delta_not_zero++;continue;}
				if (delta_not_zero==1) {b=i;delta_not_zero++;continue;}
				if (delta_not_zero==2) {c=i;delta_not_zero++;break;}
			}
			team_clear();team[a]='1';team[b]='1';team[c]='1';
			strcpy(lst[++ans],team+1);
			delta[a]--;delta[b]--;delta[c]--;
		}
	}
	for (int i=1;i<=n;i++)
		if (delta[i])
		{
			A.res=delta[i];A.pos=i;
			pq.push(A);
		}
	while(find_team())
	{
		team_clear();team[ths]='1';team[nxt]='1';strcpy(lst[++ans],team+1);
	}
	printf("%d\n",mn);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) 
			printf("%s\n",lst[i]);
	return 0;
}