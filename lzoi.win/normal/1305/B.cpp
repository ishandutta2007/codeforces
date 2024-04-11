#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN=1e4+5;
bool vis[MAXN];
vector<int> vec[MAXN];
char s[MAXN];
int main() {
	int ans=0;
	scanf("%s",s+1);
	int len=strlen(s+1);
	bool k=0;
	while(!k) {
		ans++;
		k=1;
		int l=1,r=len;
		while(l<=r) {
			if(!vis[l]&&s[l]=='(') {
				while(l<=r) {
					if(!vis[r]&&s[r]==')') break;
					r--;
				}
				if(l<r) {
					vis[l]=vis[r]=1;
					vec[ans].push_back(l);
					vec[ans].push_back(r);
					k=0;
				}
			}
			l++;
		}
		if(k) break;
	}
	printf("%d\n",--ans);
	for(int i=1;i<=ans;i++) {
		int t=vec[i].size();
		sort(vec[i].begin(),vec[i].end());
		printf("%d\n",t);
		for(int j=0;j<vec[i].size();j++)
			printf("%d ",vec[i][j]);
		puts("");
	}
	return 0;
}