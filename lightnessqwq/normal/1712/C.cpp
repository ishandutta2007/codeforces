#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans,flg;
int a[maxn];
string s;
map<int,int>mp;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=flg=0;
		scanf("%d",&n),mp.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int p=n;
		while(p>1&&a[p-1]<=a[p])
			p--;
		for(int i=1;i<p;i++)
			ans+=mp.count(a[i])==0,mp[a[i]]=1;
		int lst=p-1;
		for(int i=p;i<=n;i++)
			if(mp.count(a[i]))
				while(lst<i)
					lst++,ans+=mp.count(a[lst])==0,mp[a[lst]]=1;
		printf("%d\n",ans);
	}
	return 0;
}