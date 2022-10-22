#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

int n;
string s;
long long ans = 0;

void dfs(int l,int r){
	if(r-l<=1)return;
	int m = (l+r)/2;
	vector<vector<int>> num(3);
	{
		int mp = 0;
		for(int i=m;i<r;i++){
			if(s[i]=='-')mp++;
			else mp--;
			num[((mp%3)+3)%3].push_back(mp);
		}
	}
	rep(i,3)sort(num[i].begin(),num[i].end());
	int mp = 0;
	for(int i=m;i>=l;i--){
		if(i!=m){
			if(s[i]=='-')mp++;
			else mp--;
		}
		int ind = mp%3;
		ind +=3;
		ind %= 3;
		ind = 3-ind;
		ind %= 3;
		ans += distance(lower_bound(num[ind].begin(),num[ind].end(),-mp),num[ind].end());
	}
	dfs(l,m);
	dfs(m+1,r);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		
		scanf("%d",&n);
		//string s;
		cin>>s;
		ans = 0;
		dfs(0,n);
		cout<<ans<<endl;
	}
	
	return 0;
}