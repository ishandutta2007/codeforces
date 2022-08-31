
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
int n,m,k;
string s;
string ss;
int aa[21];
int bb[21];
int pre3[1<<10];

pair<int,int> dp[1100][1100];
void add(int i,int j){
	int x=(i&1023);
	int xx=(i-x)/1024;
	for(int ii=0;ii<(1<<10);ii++){
		int mm=pre3[(x^ii)];
		if(dp[ii][xx].a==-1){
			dp[ii][xx]={mm,j+1};
		}
		if(mm<dp[ii][xx].a){
			dp[ii][xx]={mm,j+1};
		}
	//	dp[ii][xx][__builtin_popcount((i&1023)^ii)]=j+1;
	}
}
pair<int,int> it[1000001];
int pre[1000001];
int pre2[1000001];
int vis[1000001];
int vis2[1000001];
int vis3[1<<20];
int cur[21];
int ans=-1;
pair<int,int> cot;
void remin(int ac,pair<int,int> dd){
	if(ac>ans){
		ans=ac;
		cot=dd;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m>>k;
	cin>>s;
	cin>>ss;
	for(int i=0;i<k;i++){
		aa[i]=s[i]-'0';
		bb[i]=ss[i]-'0';
	}
	for(int i=0;i<n;i++){
		cin>>it[i].a>>it[i].b;
		it[i].a--;
		it[i].b--;
	}
	for(int i=0;i<k;i++){
		cur[i]=i;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			if(aa[j]==1){
				pre[i]+=(1<<cur[j]);
			}
		}
		swap(cur[it[i].a],cur[it[i].b]);
	}
	for(int i=0;i<k;i++){
		cur[i]=i;
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<k;j++){
			if(bb[j]==1){
				pre2[i]+=(1<<cur[j]);
			}
		}
		if(i==n){
			break;
		}
		swap(cur[it[i].a],cur[it[i].b]);
	}
//	set<int> ss;
	//llo yy=0;
	for(int i=n;i>=0;i--){
		if(vis3[pre2[i]]){
			continue;
		}
		vis3[pre2[i]]=1;
		vis[i]=1;
	//	yy+=1;
	}
	//assert(yy<=200000);
	/*if(xx>184756){

	}*/
	for(int i=0;i<(1<<20);i++){
		vis3[i]=0;
	}
	for(int i=0;i<(1<<10);i++){
		pre3[i]=__builtin_popcount(i);
	}
	//ss.clear();
	for(int i=0;i<n;i++){
		if(vis3[pre[i]]){
			continue;
		}
		vis3[pre[i]]=1;
		vis2[i]=1;
	}
	for(int i=0;i<(1<<10);i++){
		for(int ii=0;ii<(1<<10);ii++){
			dp[i][ii]={-1,-1};
		}
	}
	for(int i=1;i<=n;i++){
		if(i>=m){
			if(vis2[i-m]){
				add(pre[i-m],i-m);
			}
		}
		if(vis[i]){
			int pp=(pre2[i]&(1023));
			int qq=(pre2[i]-pp)/1024;
			for(int j=0;j<(1<<10);j++){
				if(dp[pp][j].a>-1){
					int cost=k-dp[pp][j].a;
					cost-=pre3[j^qq];
					remin(cost,{dp[pp][j].b,i});
				}
				/*for(int kk=0;kk<=10;kk++){
					
				}*/
			}
		}
	}
	cout<<ans<<endl;
	cout<<cot.a<<" "<<cot.b<<endl;










	return 0;
}