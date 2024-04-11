#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int N=2e6+5;
int T,n,m,f[N],cm[N];char s[N];vector<int> pos;
void solve(){
	scanf("%d%d%s",&n,&m,s+1);
	pos.clear(),pos.push_back(-1145141);
	for(int i=1;i<=n*m;i++)if(s[i]=='1')pos.push_back(i);
	pos.push_back(9198100);
	fill(f,f+n*m+1,0);
	for(int i=1;i<pos.size()-1;i++){
		if(pos[i]-pos[i-1]>m)f[pos[i]]++;
		if(pos[i+1]-pos[i]>m)f[pos[i]+m]--;
	}
	for(int i=m;i<=n*m;i++)f[i]+=f[i-m];
	for(int i=1;i<=n*m;i++)f[i]+=f[i-1];
	fill(cm,cm+m,0);
	for(int i=1,c=0;i<=n*m;f[i]+=c,i++)
		if(s[i]=='1')c+=(!cm[i%m]),cm[i%m]=1;
	for(int i=1;i<=n*m;i++)printf("%d ",f[i]);printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}