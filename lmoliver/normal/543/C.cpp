#include<bits/stdc++.h>
using namespace std;
const int N=22;
char s[N][N];
int a[N][N];
int dp[1<<N];
int cm[N*N*2],ca[N*N*2];
vector<int> v[256];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int c=0,inst=0;
	for(int i=0;i<m;i++){
		for(char j='a';j<='z';j++)v[(int)j].clear();
		for(int j=0;j<n;j++){
			v[(int)s[j][i]].push_back(j);
		}
		for(char j='a';j<='z';j++){
			if(v[(int)j].size()>1){
				int sum=0,ma=0,mk=0;
				for(vector<int>::iterator it=v[(int)j].begin();it!=v[(int)j].end();++it){
					ma=max(ma,a[*it][i]);
					sum+=a[*it][i];
					mk|=1<<*it;
				}
				sum-=ma;
				c++;
				cm[c]=mk;
				ca[c]=sum;
			}else if(v[(int)j].size()==1){
				inst|=(1<<v[(int)j][0]);
			}
		}
	}
	for(int i=0;i<n;i++){
		int ma=1e9;
		for(int j=0;j<m;j++){
			ma=min(ma,a[i][j]);
		}
		ca[++c]=ma;
		cm[c]=1<<i;
	}
	memset(dp,0x3f,sizeof(dp));
	// cerr<<dp[0]<<endl;
	// cerr<<inst<<endl;
	for(int i=0;i<(1<<n);i++)
		if((i&inst)==i)dp[i]=0;
	// cerr<<inst<<endl;
	// cerr<<c<<endl;
	for(int i=1;i<=c;i++){
		// cerr<<i<<" "<<cm[i]<<" "<<ca[i]<<endl;
		for(int j=0;j<(1<<n);j++){
			// cerr<<j<<endl;
			dp[j]=min(dp[j],dp[j&~cm[i]]+ca[i]);
			// cerr<<j<<endl;
		}
	}
	printf("%d\n",dp[(1<<n)-1]);
	return 0;
}