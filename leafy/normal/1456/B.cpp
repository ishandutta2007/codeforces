//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
inline int read(){
	int s=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s;
}
const int N=1e6+5;
int n;
int a[N],b[N],cnt[N];
int s[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=31-__builtin_clz(a[i]),cnt[b[i]]++,s[i]=s[i-1]^a[i];
	for(int i=0;i<=31;i++) {
		if(cnt[i]>=3) {
			puts("1");
			return 0;
		}
	}
	int ans=-1;
	for(int l1=1;l1<=n;l1++)
		for(int r1=l1;r1<=n;r1++)
			for(int l2=r1+1;l2<=n;l2++)
				for(int r2=l2;r2<=n;r2++)
					if((s[r1]^s[l1-1])>(s[r2]^s[l2-1])){
						if(ans==-1) ans=r1-l1+r2-l2;
						else ans=min(ans,r1-l1+r2-l2);
					}
	cout<<ans;
	return 0;
}