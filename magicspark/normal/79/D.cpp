//By MagicSpark
/*
Problem:
Main Idea:
Status:
*/
#include<bits/stdc++.h>
#pragma optimize("Ofast")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
//#include<ext/pb_ds/assoc_container.hpp>
#pragma comment(linker, "/STACK:16000000")
//#define map gp_hash_table
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n,k,l;
int x[11],a[111];
vector<int>difs;
bool op[11111];
int dist[22][11111];
int g[22][22];
int dp[1<<20];
void bfs(int f,int p){
	cerr<<f<<" "<<p<<endl;
	queue<int>q;
	dist[f][p]=0;
	q.push(p);
	while(!q.empty()){
		int x=q.front();q.pop();
		//if(p==2&&q.front()==10000)cout<<q.front()<<endl;
		for(int i=0;i<l;i++){
			int back=x+a[i],front=x-a[i];
			if(back<=n+1&&dist[f][back]>dist[f][x]+1){
				dist[f][back]=dist[f][x]+1;
				q.push(back);
			}
			if(front>0&&dist[f][front]>dist[f][x]+1){
				dist[f][front]=dist[f][x]+1;
				q.push(front);
			}
		}
	}
	for(int i=0;i<difs.size();i++){
		g[f][i]=dist[f][difs[i]];
	}
}
int main(){
	memset(dist,inf,sizeof(dist));
	ios::sync_with_stdio(0);
	cin>>n>>k>>l;
	for(int i=0;i<k;i++)cin>>x[i],op[x[i]]=true;
	for(int i=0;i<l;i++)cin>>a[i];
	for(int i=0;i<=n+5;i++)if(op[i]!=op[i-1]){difs.push_back(i);}
	for(int i=0;i<difs.size();i++)bfs(i,difs[i]);
	int sz=difs.size();
	memset(dp,inf,sizeof(dp));
	dp[(1<<sz)-1]=0;
	for(int i=0;i<difs.size();i++)cerr<<difs[i]<<" ";cerr<<endl;
	for(int i=0;i<difs.size();i++){
		for(int j=0;j<difs.size();j++){
			cerr<<g[i][j]<<" ";
		}
		cerr<<endl;
	}
	for(int i=(1<<sz)-1;i>=0;i--){
		//cout<<i<<" "<<dp[i]<<endl;
		if(dp[i]<inf){
			for(int p=0;p<sz;p++){
				if((i>>p)&1)
				for(int q=p+1;q<sz;q++){
					if((i>>q)&1){
						dp[i^((1<<p)+(1<<q))]=min(dp[i^((1<<p)+(1<<q))],dp[i]+g[p][q]);
					}
				}
			}
		}
	}
	printf("%d\n",dp[0]==inf?-1:dp[0]);
	#ifndef ONLINE_JUDGE
		printf("\n-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}