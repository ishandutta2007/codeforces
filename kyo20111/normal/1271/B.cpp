#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
char s[222],sv[222];
vector<int> ans;
int main(){
	scanf("%d %s",&n,s);

	for(int i=0;i<n;i++) sv[i] = s[i];

	for(int i=0;i<n-1;i++){
		if(s[i] == 'B'){
			ans.push_back(i+1);
			s[i+1] = (s[i+1] == 'B' ? 'W' : 'B');
		}
	}

	if(s[n-1] == 'W'){
		printf("%d\n",ans.size());
		for(int x : ans) printf("%d ",x);
		return 0;
	}

	ans.clear();
	for(int i=0;i<n;i++) s[i] = sv[i];


	for(int i=0;i<n-1;i++){
		if(s[i] == 'W'){
			ans.push_back(i+1);
			s[i+1] = (s[i+1] == 'B' ? 'W' : 'B');
		}
	}

	if(s[n-1] == 'B'){
		printf("%d\n",ans.size());
		for(int x : ans) printf("%d ",x);
		return 0;
	}

	printf("-1");
}