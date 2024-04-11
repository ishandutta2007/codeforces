#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<int> a(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		mp[a[i]]++;
	}
	
	vector<int> cnt(400002,0);
	for(auto x:mp){
		cnt[x.second]++;
	}
	
	int dif = 0;
	int K = 40000;
	int maxi = 0;
	int N = n;
	for(int i=400001;i>=1;i--){
		n -= dif;
		dif += cnt[i];
		if((long long)i*i <= (long long)n){
			if(maxi < i * (n/i)){
				K = i;
				maxi = K*(n/i);
				N = n;
			}
		}
	}
	
	n = N;
	
	int h = K;
	int w = n / K;
	vector<int> A;
	
	priority_queue<pair<int,int>> Q;
	
	for(auto x:mp){
		int num = min(x.second,K);
		Q.emplace(num,x.first);
	}
	
	while(Q.size()!=0){
		int num = Q.top().first;
		int x = Q.top().second;
		Q.pop();
		for(int i=0;i<num;i++)A.push_back(x);
	}
	
	vector<vector<int>> ans(h,vector<int>(w,-1));
	int y = 0;
	int x = 0;
	
	for(int i=0;i<h*w;i++){
		ans[y][x] = A[i];
		y++;
		x++;
		y%=h;
		x%=w;
		if(ans[y][x]!=-1){
			x++;
			x%=w;
		}
	}
	
	cout<<h*w<<endl;
	cout<<h<<' '<<w<<endl;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(j!=0)cout<<' ';
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
	
	
	return 0;
}