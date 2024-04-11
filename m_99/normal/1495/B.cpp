#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int n;
	scanf("%d",&n);
	
	vector<int> p(n);
	rep(i,n){
		scanf("%d",&p[i]);
		p[i]--;
	}
	
	vector<int> left(n,0);
	vector<int> left2(n,0);
	rep(i,n){
		left[i] = 1;
		left2[i] = 1;
		if(i!=0 && p[i-1]<p[i])left[i] += left[i-1];
		if(i!=0 && p[i-1]>p[i])left2[i] += left2[i-1];
	}
	
	vector<int> right(n,0);
	vector<int> right2(n,0);
	for(int i=n-1;i>=0;i--){
		right[i] = 1;
		right2[i] = 1;
		if(i!=n-1 && p[i+1]<p[i])right[i] += right[i+1];
		if(i!=n-1 && p[i+1]>p[i])right2[i] += right2[i+1];
	}
	
	vector<int> L(n),R(n);
	rep(i,n){
		L[i] = max(left2[i],right2[i]);
		R[n-1-i] = max(left2[n-1-i],right2[n-1-i]);
		if(i!=0){
			L[i] = max(L[i],L[i-1]);
			R[n-1-i] = max(R[n-1-i],R[n-1-i+1]);
		}
	}
	
	rep(i,n-1){
		left2[i+1] = max(left2[i],left2[i+1]);
		right2[n-1-i-1] = max(right2[n-1-i],right2[n-1-i-1]);
	}
	
	

	
	int ans = 0;
	rep(i,n){
		if(left[i]!=right[i])continue;
		if(left[i]==1||right[i]==1)continue;
		if((left[i]&1)==0)continue;
		int m = 0;
		m = max(m,left2[i+1-left[i]]);
		m = max(m,right2[i-1+right[i]]);
		if(i+1-left[i]-1>=0){
			m = max(m,L[i+1-left[i]-1]);
		}
		if(i-1+right[i]+1<n){
			m = max(m,R[i-1+right[i]+1]);
		}
		//if(i==2)cout<<m<<endl;
		if(m < left[i])ans++;
	}
	
	cout<<ans<<endl;
	
	
    return 0;
}