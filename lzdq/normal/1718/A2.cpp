#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
int n,a[MAXN],b[MAXN],f[MAXN],ans;
unordered_map<int,int> mp;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),b[i]=b[i-1]^a[i];
		mp.clear();
		mp[0]=0;
		for(int i=1; i<=n; i++){
			auto it=mp.find(b[i]);
			f[i]=f[i-1];
			if(it!=mp.end()){
				if(it->second+1>f[i])
					f[i]=it->second+1;
				mp[b[i]]=max(mp[b[i]],f[i]);
			}else mp[b[i]]=f[i];
		}
		printf("%d\n",n-f[n]);
	}
	return 0;
}