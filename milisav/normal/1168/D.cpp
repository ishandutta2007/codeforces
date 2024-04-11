#include<bits/stdc++.h>
using namespace std;
int cnt[160000][2][30];
int gnt[160000][2][30];
int ct[160000][30];
bool ang[160000][2];
bool ag[160000];
int p[160000];
int pc[160000];
vector<int> c[160000];
bool anc[160000];
int r[160000];
int n,q;
void dfs(int u,int t=0) {
	r[u]=t;
	anc[abs(t)]=true;
	if(t>=0) gnt[t][0][pc[u]]++,cnt[t][0][pc[u]]++;
	if(t<0) gnt[-t][1][pc[u]]++,cnt[-t][1][pc[u]]++;
	int v;
	for(int i=0;i<c[u].size();i++) {
		v=c[u][i];
		if(c[u].size()==2 && i==0) t=u;
		if(c[u].size()==2 && i==1) t=-u;
		//printf("%d %d %d\n",u,v,t);
		dfs(v,t);
	}
	if(anc[u]) {
		int j;
		if(r[u]>=0) j=0;
		else j=1;
		int rp=abs(r[u]);
		if(ang[u][0] && ang[u][1]) {
			int k0=cnt[u][0][0];
			int k1=cnt[u][1][0];
			for(int s=1;s<=26;s++) {
				ct[u][s]=max(cnt[u][0][s],cnt[u][1][s]);
				if(cnt[u][0][s]>cnt[u][1][s]) k1-=(cnt[u][0][s]-cnt[u][1][s]);
				if(cnt[u][1][s]>cnt[u][0][s]) k0-=(cnt[u][1][s]-cnt[u][0][s]);
			}
			if(min(k0,k1)>=0 && k0==k1) ct[u][0]=min(k0,k1);
			else ag[u]=false;
		}
		else ag[u]=false;
		if(ag[u]) {
			for(int s=0;s<=26;s++) cnt[rp][j][s]=gnt[rp][j][s]+ct[u][s];
			ang[rp][j]=true;
		}
		else {
			ag[rp]=false;
			ang[rp][j]=false;
		}
	}
}
void update(int u,int cc=-1) {
	if(cc!=-1) {
		int j;
		if(r[u]>=0) j=0;
		else j=1;
		int rp=abs(r[u]);
		gnt[rp][j][pc[u]]--,cnt[rp][j][pc[u]]--;
		pc[u]=cc;
		gnt[rp][j][pc[u]]++,cnt[rp][j][pc[u]]++;
		update(rp);
		return;
	}
	if(u==0) {
		if(ang[u][0]) {
			int sum=0;
			for(int i=1;i<=26;i++) {
				//cout<<cnt[0][0][0]<<" "<<cnt[0][0][i]<<endl;
				sum+=i*(cnt[0][0][0]+cnt[0][0][i]);
			}
			printf("Shi %d\n",sum);
		}
		else {
			printf("Fou\n");
		}
		return;
	}
	else {
		int j;
		if(r[u]>=0) j=0;
		else j=1;
		int rp=abs(r[u]);
		if(ang[u][0] && ang[u][1]) {
			int k0=cnt[u][0][0];
			int k1=cnt[u][1][0];
			for(int s=1;s<=26;s++) {
				ct[u][s]=max(cnt[u][0][s],cnt[u][1][s]);
				if(cnt[u][0][s]>cnt[u][1][s]) k1-=(cnt[u][0][s]-cnt[u][1][s]);
				if(cnt[u][1][s]>cnt[u][0][s]) k0-=(cnt[u][1][s]-cnt[u][0][s]);
			}
			if(min(k0,k1)>=0 && k0==k1) {
				ct[u][0]=min(k0,k1);
				ag[u]=true;
			}
			else ag[u]=false;
		}
		else ag[u]=false;
		if(ag[u]) {
			for(int s=0;s<=26;s++) cnt[rp][j][s]=gnt[rp][j][s]+ct[u][s];
			ang[rp][j]=true;
		}
		else {
			ag[rp]=false;
			ang[rp][j]=false;
		}
		update(rp);
	}
}
int main() {
	scanf("%d %d",&n,&q);
	for(int i=0;i<=n;i++) ag[i]=ang[i][0]=ang[i][1]=true;
	char ch[2];
	for(int i=2;i<=n;i++) {
		scanf("%d %s",&p[i],ch);
		if(ch[0]=='?') pc[i]=0;
		else pc[i]=ch[0]-'a'+1;
		c[p[i]].push_back(i);
	}
	pc[1]=28;
	dfs(1);
	int x;
	int cc;
	while(q--) {
		scanf("%d %s",&x,ch);
		if(ch[0]=='?') cc=0;
		else cc=ch[0]-'a'+1;
		update(x,cc);
	}
	return 0;
}