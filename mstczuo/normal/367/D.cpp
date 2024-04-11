# include <iostream>
# include <cstdio>
using namespace std;

const int N = 100010;
int a[N],cnt[21];
bool dis[1<<20|1];
int main() {
	int n, m, d, s, t, ans=0;
	scanf("%d%d%d", &n, &m, &d);
	for(int i=0; i<m; i++) {
		scanf("%d", &s);
		for(int j=0; j<s; j++) 
			scanf("%d", &t),a[t-1] = i;
	}
	for(int i=0; i<d; i++) cnt[a[i]] ++;
	for(int i=d; i<=n; i++) {
		s = 0;
		for(int j=0; j<m; j++) if(cnt[j]) s|=1<<j;
		cnt[a[i-d]]--; cnt[a[i]]++; dis[s]=true;
	}
	for(int i=0; i<(1<<m); i++)
		if(dis[i]) for(int j=0;j<m;j++)
			dis[i|(1<<j)] = true;
	for(int i=0; i<(1<<m); i++)
		if( !dis[i] ) {
			s = 0; t = i;
			while(t)t -= t&(-t),s++;
			ans=max(ans,s);
		}
	cout<<m-ans<<endl;
	return 0;
}