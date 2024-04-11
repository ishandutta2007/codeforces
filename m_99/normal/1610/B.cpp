#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

bool check(vector<int> a,int t){
	vector<int> b;
	rep(i,a.size()){
		if(a[i]==t)continue;
		b.push_back(a[i]);
	}
	vector<int> c(b.rbegin(),b.rend());
	return b==c;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		
		bool f = false;
		if(check(a,0))f = true;
		rep(i,n){
			int x = i;
			int y = n-1-i;
			if(a[x]!=a[y]){
				if(check(a,a[x])||check(a,a[y])){
					f = true;
				}
				break;
			}
		}
		if(f)printf("YES\n");
		else printf("NO\n");
		
	}
	
	return 0;
}