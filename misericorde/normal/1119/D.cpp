#include <bits/stdc++.h>
#define ll long long
struct query {
	ll len;int id;
}Q[100005];
ll s[100005],answer[100005],ans=0,arr[100005],l,r;
int n,q,tail=0;
int cmp(query a,query b) {return a.len<b.len;}


int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) std::cin>>s[i];
	std::sort(s+1,s+n+1);
	for (int i=1;i<n;++i) {arr[++tail]=s[i+1]-s[i];}
	std::sort(arr+1,arr+tail+1);
	scanf("%d",&q);
	for (int i=1;i<=q;++i) {
		std::cin>>l>>r;
		Q[i].len=(r-l+1);
		Q[i].id=i;
	}std::sort(Q+1,Q+q+1,cmp);
	int last=n,p=1; ll lp=0;
	for (int i=1;i<=q;++i){
		while (arr[p]<Q[i].len&&p<=tail) {
			ans+=(ll)last*(arr[p]-lp);
			lp=arr[p]; last--; p++;
		}ans+=(ll)last*(Q[i].len-lp);
		lp=Q[i].len;
		answer[Q[i].id]=ans;
	} for (int i=1;i<=q;++i) std::cout<<answer[i]<<" ";
	return 0;
}