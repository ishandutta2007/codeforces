#include <bits/stdc++.h>
using namespace std;

pair<int,int> w[100005];
int n;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		w[i]=make_pair(a,b);
	}
	sort(w,w+n);
	int r=0,q=-1;
	for(int i=0;i<n;++i){
		r+=w[i].second<q;
		q=max(q,w[i].second);
	}
	printf("%d\n",r);
	return 0;
}