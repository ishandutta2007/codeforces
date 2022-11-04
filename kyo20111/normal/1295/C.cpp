#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, mx[256];
char s[100100], t[100100];
vector<int> v[256];
int main(){
	scanf("%d",&T);
	while(T--){
		for(int i='a';i<='z';i++) v[i].clear(), mx[i] = 0;

		scanf(" %s %s",s,t);
		int ans = 1;
		for(int i=0;s[i];i++) v[s[i]].push_back(i+1), mx[s[i]] = i+1;
		for(int i='a';i<='z';i++) sort(v[i].begin(), v[i].end());

		int cur = 0, flag = 0;
		for(int i=0;t[i];i++){
			if(!mx[t[i]]){
				flag = 1;
				break;
			}

			if(cur >= mx[t[i]]) cur = 0, ans++;
			int it = *lower_bound(v[t[i]].begin(), v[t[i]].end(), cur+1);
			cur = it;
		}

		printf("%d\n",flag ? -1 : ans);
	}
}