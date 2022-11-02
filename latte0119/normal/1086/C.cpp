#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,K;
char s[1111111],a[1111111],b[1111111];

void solve(){
	scanf("%lld",&K);
	scanf("%s",&s);
	scanf("%s",&a);
	scanf("%s",&b);

	N=strlen(s);

	rep(uku,2){
		bool oka=false,okb=false;
		vint ans(K,-1);
		vint used(K,0);
		bool ok=true;
		for(int i=0;i<N;i++){
			vint lis;
			int c=s[i]-'a';
			for(int j=0;j<K;j++){
				if(ans[c]!=-1&&ans[c]!=j)continue;
				if(ans[c]==-1&&used[j])continue;
				if(!oka&&a[i]-'a'>j)continue;
				if(!okb&&b[i]-'a'<j)continue;
				lis.pb(j);
			}
			if(lis.size()==0){
				ok=false;
				break;
			}

			int x=-1,y=-1;
			for(auto z:lis){
				if(!oka&&a[i]-'a'==z)x=z;
				if(!okb&&b[i]-'a'==z)y=z;
			}

			if(x!=-1&&y!=-1){
				if(lis.size()>=2&&lis[1]!=y){
					ans[c]=lis[1];
					used[lis[1]]=true;
				}
				else if(uku){
					ans[c]=x;
					used[x]=true;
				}
				else{
					ans[c]=y;
					used[y]=true;
				}
			}
			else if(x!=-1){
				ans[c]=lis.back();
				used[lis.back()]=true;
			}
			else{
				ans[c]=lis[0];
				used[lis[0]]=true;
			}

			if(ans[c]!=x)oka=true;
			if(ans[c]!=y)okb=true;
		}
		if(!ok)continue;
		for(int i=0;i<K;i++){
			if(ans[i]!=-1)continue;
			for(int j=0;j<K;j++)if(!used[j]){
				ans[i]=j;
				used[j]=true;
				break;
			}
		}
		puts("YES");
		rep(i,K){
			printf("%c",(char)('a'+ans[i]));
		}
		puts("");
		return;
	}

	puts("NO");
}

signed main(){
	int t;scanf("%lld",&t);
	while(t--)solve();
	return 0;
}