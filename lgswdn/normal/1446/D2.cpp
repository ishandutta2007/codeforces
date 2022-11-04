#include<bits/stdc++.h>
using namespace std;
const int N=200009;

int n,a[N],cnt[N],mode,fsm[N],tmp[N],ans;
void larg(int x) {
	int sm=0, res=0;
	memset(fsm,0,sizeof(fsm));
	for(int i=1;i<=n;i++) {
		if(a[i]==mode) sm++;
		else if(a[i]==x) sm--;
		if(sm&&!fsm[sm]) fsm[sm]=i;
		res=max(res,i-fsm[sm]);
	}
	ans=max(ans,res);
}
void smal(int x) {
	int l=1,p=0,res=0;
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=n;i++) {
		tmp[a[i]]++;
		if(tmp[a[i]]==x) p++;
		while(l<=i&&tmp[a[i]]>x) {
			if(tmp[a[l]]==x) --p;
			tmp[a[l++]]--;
		}
		if(p>=2) res=max(res,i-l+1);
	}
	ans=max(ans,res);
}
int main() {
	scanf("%d",&n);
	if(n==1) {
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++) {
		if(cnt[a[i]]>cnt[mode]) mode=a[i];
	}
	for(int i=1;i<=200000;i++) {
		if(!cnt[i]) continue;
		if(i!=mode&&cnt[i]==cnt[mode]) {
			printf("%d\n",n);
			return 0;
		}
		if(cnt[i]>sqrt(n)) larg(i);
	}
	for(int i=1;i<=sqrt(n);i++) smal(i);
	printf("%d\n",ans);
	return 0;
}
//