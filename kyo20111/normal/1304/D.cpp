#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, c[200200], a[200200];
char s[200200];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %s",&n,s+1);
		for(int i=1;i<=n+1;i++) c[i] = a[i] = 0;
		vector<int> v;
		if(s[1] == '>') v.push_back(1);
		for(int i=2;i<n;i++){
			if(s[i-1] == '<' && s[i] == '>') v.push_back(i);
		}

		int l = n;
		for(int i=0;i<v.size();i++){
			int j = v[i];
			while(j <= n && s[j] == '>'){
				a[j] = l--;
				j++;
			}
		}

		l = 1;
		for(int i=n;i>=1;i--){
			if(!a[i]){
				int j = i;
				while(j > 0 && !a[j]) j--;
				for(int k=j+1;k<=i;k++) a[k] = l++;
				i = j+1;
			}
		}

		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");

		for(int i=1;i<=n+1;i++) c[i] = a[i] = 0;
		c[1] = 1, c[n+1] = n+1;
		for(int i=2;i<=n;i++){
			if(s[i-1] == '<') c[i] = c[i-1]+1;
			if(s[i-1] == '>') c[i] = c[i-1];
		}
		int u = 1;
		for(int i=1;i<=n+1;i++){
			if(c[i] > u){
				a[i-1] = u;
				u++;
			}
		}
		for(int i=n;i>=1;i--) if(!a[i]) a[i] = u++;
		for(int i=1;i<=n;i++) printf("%d ",a[i]);
		puts("");
	}
}