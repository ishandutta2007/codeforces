#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
inline int read(){
	int v=0,f=1;
	char c=getchar();
	while (c<'0' || c>'9'){
		if (c=='-') f=-1;
		c=getchar();
	}
	while (c>='0' && c<='9'){
		v=v*10+c-'0';
		c=getchar();
	}
	return v*f;
}
const int Maxn=105;
int cnt[Maxn][26];
int S1[Maxn],S2[Maxn],S3[Maxn];
char tmp[Maxn];
void Query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	memset(cnt,0,sizeof(cnt));
	int c=(r-l+1)*(r-l+2)/2;
	for (int i=0;i<c;i++){
		scanf("%s",tmp);
		int l=strlen(tmp);
		for (int j=0;j<l;j++){
			cnt[l][tmp[j]-'a']++;
		}
	}
}
int ans[Maxn];
vector<pair<int,int> > G[Maxn];
bool vis[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	if (n==1){
		Query(1,1);
		for (int i=0;i<26;i++){
			if(cnt[1][i]){
				printf("! %c\n",i+'a');
				fflush(stdout);
				return 0;
			}
		}
	}
	int l=1,r=n,mid=l+r>>1;
	vector<int> V;
	if (mid-l==r-mid){
		Query(1,n);
		int T=(n+1)/2;
		for (int i=T;i>=1;i--){
			for (int j=0;j<26;j++){
				S1[i]+=cnt[i][j]*j;
				S1[i]-=cnt[i-1][j]*j;
			}
			for (int j=i+1;j<=T;j++){
				S1[i]-=S1[j];
			}
		}
		for (int i=1;i<=T;i++){
			int x=i,y=n+1-i;
			if (x==y){
				ans[x]=S1[i];
				V.pb(x);
			}
			else{
				G[x].pb(mp(y,S1[i]));
				G[y].pb(mp(x,S1[i]));
			}
		}
		Query(1,mid-1);
		T=mid/2;
		for (int i=T;i>=1;i--){
			for (int j=0;j<26;j++){
				S2[i]+=cnt[i][j]*j;
				S2[i]-=cnt[i-1][j]*j;
			}
			for (int j=i+1;j<=T;j++){
				S2[i]-=S2[j];
			}
		}
		for (int i=1;i<=T;i++){
			int x=i,y=mid-i;
			if (x==y){
				ans[x]=S2[i];
				V.pb(x);
			}
			else{
				G[x].pb(mp(y,S2[i]));
				G[y].pb(mp(x,S2[i]));
			}
		}
		Query(mid,n);
		T=(n-mid+2)/2;
		for (int i=T;i>=1;i--){
			for (int j=0;j<26;j++){
				S3[i]+=cnt[i][j]*j;
				S3[i]-=cnt[i-1][j]*j;
			}
			for (int j=i+1;j<=T;j++){
				S3[i]-=S3[j];
			}
		}
		for (int i=1;i<=T;i++){
			int x=i+mid-1,y=mid+n-x;
			if (x==y){
				ans[x]=S3[i];
				V.pb(x);
			}
			else{
				G[x].pb(mp(y,S3[i]));
				G[y].pb(mp(x,S3[i]));
			}
		}
		while (!V.empty()){
			int x=V.back();V.pop_back();
			if (vis[x]) continue;
			vis[x]=true;
			for (int i=0;i<G[x].size();i++){
				int A=G[x][i].first,S=G[x][i].second;
				ans[A]=S-ans[x];
				V.pb(A);
			}
		}
		printf("! ");
		for (int i=1;i<=n;i++){
			putchar(ans[i]+'a');
		}
		printf("\n");
		fflush(stdout);
		return 0;
	}
	
	Query(1,n);
	int T=(n+1)/2;
	for (int i=T;i>=1;i--){
		for (int j=0;j<26;j++){
			S1[i]+=cnt[i][j]*j;
			S1[i]-=cnt[i-1][j]*j;
		}
		for (int j=i+1;j<=T;j++){
			S1[i]-=S1[j];
		}
	}
	for (int i=1;i<=T;i++){
		int x=i,y=n+1-i;
		if (x==y){
			ans[x]=S1[i];
			V.pb(x);
		}
		else{
			G[x].pb(mp(y,S1[i]));
			G[y].pb(mp(x,S1[i]));
		}
	}
	Query(1,mid);
	T=(mid+1)/2;
	for (int i=T;i>=1;i--){
		for (int j=0;j<26;j++){
			S2[i]+=cnt[i][j]*j;
			S2[i]-=cnt[i-1][j]*j;
		}
		for (int j=i+1;j<=T;j++){
			S2[i]-=S2[j];
		}
	}
	for (int i=1;i<=T;i++){
		int x=i,y=mid+1-i;
		if (x==y){
			ans[x]=S2[i];
			V.pb(x);
		}
		else{
			G[x].pb(mp(y,S2[i]));
			G[y].pb(mp(x,S2[i]));
		}
	}
	Query(mid,n);
	T=(n-mid+2)/2;
	for (int i=T;i>=1;i--){
		for (int j=0;j<26;j++){
			S3[i]+=cnt[i][j]*j;
			S3[i]-=cnt[i-1][j]*j;
		}
		for (int j=i+1;j<=T;j++){
			S3[i]-=S3[j];
		}
	}
	for (int i=1;i<=T;i++){
		int x=i+mid-1,y=mid+n-x;
		if (x==y){
			ans[x]=S3[i];
			V.pb(x);
		}
		else{
			G[x].pb(mp(y,S3[i]));
			G[y].pb(mp(x,S3[i]));
		}
	}
	while (!V.empty()){
		int x=V.back();V.pop_back();
		if (vis[x]) continue;
		vis[x]=true;
		for (int i=0;i<G[x].size();i++){
			int A=G[x][i].first,S=G[x][i].second;
			ans[A]=S-ans[x];
			V.pb(A);
		}
	}
	printf("! ");
	for (int i=1;i<=n;i++){
		putchar(ans[i]+'a');
	}
	printf("\n");
	fflush(stdout);
	return 0;
}