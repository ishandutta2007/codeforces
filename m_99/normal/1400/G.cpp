#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000
struct unionfind{
	vector<int> data;
	vector<int> size;
	unionfind(int n){
		for(int i=0;i<n;i++){
			data.push_back(i);
			size.push_back(1);
		}
	}
	
	int find(int x){
		if(data[x]==x)return x;
		return data[x]=find(data[x]);
	}
	
	bool unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(size[x]>size[y])swap(x,y);
		data[x]=y;
		size[y]+=size[x];
		return true;
	}
	
	bool check(int x,int y){
		return (find(x)==find(y));
	}
	
	int get_size(int x){
		int X = find(x);
		return size[X];
	}
};

int beki(long long a,long long b,int M = modulo){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=((long long)x*a)%M;
		}
		a=((long long)a*a)%M;
		b>>=1;
	}
	return x;
}


int gyakugen(int a){
	return beki(a,modulo-2);
}

struct combi{
	deque<int> kaijou;
	deque<int> kaijou_;
	
	combi(int n){
		kaijou.push_back(1);
		for(int i=1;i<=n;i++){
			kaijou.push_back(mod(kaijou[i-1]*i));
		}
		
		int b=gyakugen(kaijou[n]);
		
		kaijou_.push_front(b);
		for(int i=1;i<=n;i++){
			int k=n+1-i;
			kaijou_.push_front(mod(kaijou_[0]*k));
		}
	}
	
	int combination(int n,int r){
		if(r>n)return 0;
		int a = mod(kaijou[n]*kaijou_[r]);
		a=mod(a*kaijou_[n-r]);
		return a;
	}
	
	int junretsu(int a,int b){
		int x = mod(kaijou_[a]*kaijou_[b]);
		x=mod(x*kaijou[a+b]);
		return x;
	}
	
	int catalan(int n){
		return mod(combination(2*n,n)*gyakugen(n+1));
	}
	
};

int main(){
	
	int n,m;
	cin>>n>>m;
	
	vector<int> l(n),r(n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&l[i],&r[i]);
	}
	
	unionfind uf(n);
	vector<int> a(m),b(m);
	for(int i=0;i<m;i++){
		scanf("%d %d",&a[i],&b[i]);
		a[i]--;b[i]--;
		uf.unite(a[i],b[i]);
	}
	
	vector<vector<int>> X(n,vector<int>());
	for(int i=0;i<n;i++){
		X[uf.find(i)].push_back(i);
	}
	
	vector<int> imos(n+5,0);
	vector<vector<vector<int>>> IMOS(0,vector<vector<int>>());
	for(int i=0;i<n;i++){
		if(X[i].size()==0)continue;
		if(X[i].size()==1){
			imos[l[i]]++;
			imos[r[i]+1]--;
			continue;
		}
		IMOS.push_back(vector<vector<int>>(n+5,vector<int>(X[i].size()+1,0)));
		sort(X[i].begin(),X[i].end());
		
		for(int j=0;j<(1<<X[i].size());j++){
			vector<int> inds;
			int cnt = 0;
			for(int k=0;k<X[i].size();k++){
				if((j>>k)&1){
					cnt++;
					inds.push_back(X[i][k]);
				}
			}
			
			int L = 0,R = n-1;
			for(int k=0;k<inds.size();k++){
				L = max(L,l[inds[k]]);
				R = min(R,r[inds[k]]);
			}
			
			if(L>R)continue;
			bool f = true;
			for(int k=0;k<m;k++){
				if(binary_search(inds.begin(),inds.end(),a[k])&&binary_search(inds.begin(),inds.end(),b[k])){
					f=false;
					break;
				}
			}
			if(!f)continue;
			IMOS.back()[L][cnt]++;
			IMOS.back()[R+1][cnt]--;
		}
	}
	combi C(500000);
	for(int i=1;i<imos.size();i++)imos[i]+=imos[i-1];

	for(int i=0;i<IMOS.size();i++){
		for(int j=1;j<IMOS[i].size();j++){
			for(int k=0;k<IMOS[i][j].size();k++){
				IMOS[i][j][k] += IMOS[i][j-1][k];
			}
		}
	}

	
	int ans = 0;
	vector<int> dp(23,0);
	vector<int> ndp(23,0);
	for(int i=1;i<imos.size();i++){
		dp[0] = 1;
		for(int j=0;j<IMOS.size();j++){
			fill(ndp.begin(),ndp.end(),0);
			for(int k=0;k<IMOS[j][i].size();k++){
				int t = IMOS[j][i][k];
				if(t==0)break;
				for(int l=0;l<=22;l++){
					if(l+k>22)break;
					if(dp[l]==0)break;
					ndp[l+k] += t*dp[l];
				}				
			}
			swap(dp,ndp);
		}
		for(int j=0;j<=22;j++){
			if(j+imos[i]<i)continue;
			int t = mod(C.combination(imos[i],i-j)*dp[j]);
			ans = mod(ans + t);
		}
		fill(dp.begin(),dp.end(),0);
	}
	
	cout<<ans<<endl;
	
	return 0;
}