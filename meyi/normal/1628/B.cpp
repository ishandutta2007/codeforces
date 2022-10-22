#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
map<string,bool>vis;
inline string rev(string s){
	string t=s;
	reverse(t.begin(),t.end());
	return t;
}
string s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		vis.clear();
		for(ri i=1;i<=n;++i)cin>>s[i];
		bool ans=false;
		for(ri i=1;i<=n;++i){
			if(ans)break;
			if(s[i].size()==1){ans=true;break;}
			if(vis[rev(s[i])]){ans=true;break;}
			if(s[i]==rev(s[i])){ans=true;break;}
			if(s[i].size()==2){
				for(char j='a';j<='z';++j)
					if(vis[rev(s[i])+j]){
						ans=true;break;
					}
			}
			if(s[i].size()==3){
				if(vis[rev(s[i].substr(1,2))]){ans=true;break;}
			}
			vis[s[i]]=true;
		}
		puts(ans?"YES":"NO");
	}
	return 0;
}