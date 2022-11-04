#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, ans;
char s[1515][33],f[33],chk[256];
set<string> st;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]);
	for(int i=1;i<=n;i++) st.insert(s[i]);

	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){

			for(int k=0;k<m;k++){
				if(s[i][k] == s[j][k]) f[k] = s[i][k];
				else{
					chk[s[i][k]]++;
					chk[s[j][k]]++;
					if(!chk['S']) f[k] = 'S';
					if(!chk['E']) f[k] = 'E';
					if(!chk['T']) f[k] = 'T';
					chk['S'] = chk['E'] = chk['T'] = 0;
				}
			}

			if(st.count(f)) ans++;
		}
	}
	if(ans) printf("%d",ans/3);
	else printf("0"); 
}