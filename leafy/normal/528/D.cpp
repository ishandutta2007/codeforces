#include<bits/stdc++.h>
using namespace std;
const int N=200005;
char s[N],t[N];
int n,m,k;
int a[4][N];
map<char,int> mp;
bitset<N> ans,ss[4];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s);scanf("%s",t);
	mp['A']=0,mp['T']=1,mp['G']=2,mp['C']=3;
	for(int i=0;i<n;i++){
		a[mp[s[i]]][max(0,i-k)]++;
		a[mp[s[i]]][min(n,i+k+1)]--;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++){
			a[j][i]+=a[j][i-1];
			if(a[j][i]) ss[j][i]=1;
		}
	ans.set();
	for(int i=0;i<m;i++) ans&=(ss[mp[t[i]]]>>i);
	printf("%d",ans.count());
	return 0;
}