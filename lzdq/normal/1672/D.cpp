#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN],b[MAXN];
int cnt[MAXN];
bool Calc(){
	for(int i=1; i<=n; i++)
		cnt[i]=0;
	for(int i=1,j=1; i<=n; i++){
		int x=b[i];
		if(i==n||b[i]!=b[i+1]){	// fixed
			while(j<=n&&a[j]!=x) cnt[a[j++]]++;
			if(j>n) return 0;
			j++;
		}else{
			if(cnt[x]) cnt[x]--;
			else{
				while(j<=n&&a[j]!=x) cnt[a[j++]]++;
				if(j>n) return 0;
				j++;
			}
		}
	}
	return 1;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		for(int i=1; i<=n; i++)
			scanf("%d",b+i);
		if(Calc()) puts("YES");
		else puts("NO");
	}
	return 0;
}