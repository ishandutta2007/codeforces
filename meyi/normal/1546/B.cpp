#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int cnt[maxn][26],m,n,t;
string s;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			cin>>s;
			for(ri j=0;j<m;++j)++cnt[j][s[j]-'a'];
		}
		for(ri i=1;i<n;++i){
			cin>>s;
			for(ri j=0;j<m;++j)--cnt[j][s[j]-'a'];
		}
		for(ri i=0;i<m;++i)
			for(ri j=0;j<26;++j){
				if(cnt[i][j]==1)putchar(j+'a');
				cnt[i][j]=0;
			}
		putchar(10);
	}
}