#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

void Put(vector<int> a,int ans){
	printf("%d\n",ans);
	rep(i,a.size()){
		if(i!=0)printf(" ");
		printf("%d",a[i]+1);
	}
	printf("\n");
}


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n);
		vector<int> cnt(n,0);
		rep(i,n){
			scanf("%d",&a[i]);
			a[i]--;
			cnt[a[i]] ++;
		}
		
		int S = 0;
		rep(i,n){
			if(cnt[i]>0)S++;
		}
		
		if(S==n){
			Put(a,n);
			continue;
		}
		
		if(S==n-1){
			int D = -1;
			rep(i,n){
				if(cnt[i]==0)D = i;
			}
			rep(i,n){
				if(cnt[a[i]]!=2)continue;
				if(i!=D){
					a[i] = D;
					break;
				}
			}
			Put(a,n-1);
			continue;
		}
		vector<int> vs;
		rep(i,n){
			if(cnt[i]==0)vs.push_back(i);
		}
		vector<int> inds;
		int ans = 0;
		rep(i,n){
			cnt[a[i]]--;
			if(cnt[a[i]]!=0){
				inds.push_back(i);
			}
			else ans++;
		}
		while(vs.size()>2){
			int x = vs.back();
			vs.pop_back();
			int y = vs.back();
			vs.pop_back();
			if(inds.back()==x){
				vs.push_back(x);
				a[inds.back()] = y;
			}
			else{
				vs.push_back(y);
				a[inds.back()] = x;
			}
			inds.pop_back();
		}
		
		if(vs.size()==2){
			if(inds[0]==vs[0]||inds[1]==vs[1])swap(inds[0],inds[1]);
		}
		rep(i,inds.size()){
			a[inds[i]] = vs[i];
		}
		
		Put(a,ans);
		
	}	
	
	return 0;
}