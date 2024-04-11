#include <bits/stdc++.h>
#define ll long long
#define maxn 200005
const ll ouuan=998244353;
int n,rank[maxn];
ll A[maxn],B[maxn],ans;
int cmp(int a,int b) {return A[a]>A[b];}

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;++i) {
		std::cin>>A[i]; A[i]=A[i]*(ll)(i)*(ll)(n-i+1); rank[i]=i;
	}std::sort(rank+1,rank+n+1,cmp); 
	for (int i=1;i<=n;++i) {
		std::cin>>B[i];
	}std::sort(B+1,B+n+1);
	for (int i=1;i<=n;++i) {
		ans=(ans+B[i]*(A[rank[i]]%ouuan))%ouuan;
	}std::cout<<ans;
	return 0;
}