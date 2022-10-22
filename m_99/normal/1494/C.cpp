#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1200000000

int get(vector<int> a,vector<int> b){
	
	vector<int> sum(a.size()+1,0);
	
	for(int i=a.size()-1;i>=0;i--){
		if(binary_search(b.begin(),b.end(),a[i]))sum[i] = 1;
		sum[i] += sum[i+1];
	}
	
	a.push_back(Inf);
	
	int ret = 0;
	int pos = 0;
	
	rep(i,a.size()-1){
		int cur = 0;
		while(pos!=b.size() && a[i]>b[pos])pos++;
		while(pos!=b.size() && a[i+1]>b[pos]){
			cur = max(cur,(int)distance(lower_bound(b.begin(),b.end(),b[pos] - i),b.begin()+pos+1));
			pos++;
		}

		cur += sum[i+1];
		ret = max(ret,cur);
	}
	return ret;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		vector<int> X,Y,Z,W;
		rep(i,n){
			int a;
			scanf("%d",&a);
			if(a>=0)X.push_back(a);
			else Y.push_back(-a);
		}
		rep(i,m){
			int a;
			scanf("%d",&a);
			if(a>=0)Z.push_back(a);
			else W.push_back(-a);
		}
		
		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
		sort(Z.begin(),Z.end());
		sort(W.begin(),W.end());
		
		printf("%d\n",get(X,Z)+get(Y,W));
		
	}
	
    return 0;
}