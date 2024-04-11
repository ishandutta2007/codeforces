#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,m,a[N];pair<int,int> b[N],c[N];
void remake(){
	auto tmp=b[1];int mm=0;
	for(int i=2;i<=m;i++)if(b[i].first==tmp.first)tmp.second+=b[i].second;else b[++mm]=tmp,tmp=b[i];
	b[++mm]=tmp,m=mm;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)b[i]=make_pair(a[i],1);
	m=n;remake();
	while(1){
		int mm=0;
		for(int i=1;i<=m;i++)if(b[i].second>1)c[++mm]=make_pair(0,b[i].second-1);
		for(int i=1;i<m;i++)c[++mm]=make_pair(b[i+1].first-b[i].first,1);
		for(int i=1;i<=mm;i++)b[i]=c[i];m=mm;
		sort(b+1,b+mm+1),remake();
		if(mm==1){printf("%d\n",b[1].first);return;}
		else if(mm==2&&b[1].first==0){printf("%d\n",b[2].first);return;}
	}

}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}