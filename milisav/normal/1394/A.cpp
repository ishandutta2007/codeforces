#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 500000
using namespace std;
int n,m,d;
int a[maxn];
vector<int> s;
vector<int> g;
int main() {
    scanf("%d %d %d",&n,&d,&m);
	for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        if(a[i]<=m) s.push_back(a[i]);
        else g.push_back(a[i]);
	}
	sort(s.begin(),s.end());
	sort(g.begin(),g.end());
	long long ans=0;
	long long la=0,ra=0;
	for(int i=0;i<s.size();i++) la+=s[i];
	ans=la;
    reverse(g.begin(),g.end());
    int j=0;
    for(int i=0;i<g.size();i++) {
        ra+=g[i];
        int jg=n-i*(d+1)-1;
        if(jg<0) break;
        while(j+jg<s.size()) {
            la-=s[j];
            j++;
        }
        ans=max(ans,la+ra);
    }
    printf("%lld",ans);
	return 0;
}