#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4e5+10;
int b[maxn],bl,cnt[maxn],l[maxn],n,r[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d%d",l+i,r+i);
		b[++bl]=l[i],b[++bl]=r[i];
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	for(ri i=1;i<=n;++i){
		l[i]=lower_bound(b+1,b+bl+1,l[i])-b;
		r[i]=lower_bound(b+1,b+bl+1,r[i])-b;
		++cnt[l[i]],--cnt[r[i]+1];
	}
	for(ri i=1;i<=bl;++i){
		cnt[i]+=cnt[i-1];
		if(cnt[i]>2)return puts("NO"),0;
	}
	puts("YES");
	return 0;
}