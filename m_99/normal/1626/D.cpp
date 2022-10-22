#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

long long sum(long long n){
	long long ret = n;
	ret *= n+1;
	ret /= 2;
	return ret;
}

long long sum(long long l,long long r){
	return sum(r) - sum(l-1);
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<int> a(n+1);
		rep(i,n){
			int x;
			scanf("%d",&x);
			a[x]++;
		}
		rep(i,n){
			a[i+1] += a[i];
		}
		int ans = Inf;
		rep(i,20){
			rep(j,20){
				int d0 = distance(a.begin(),upper_bound(a.begin(),a.end(),1<<i));
				d0--;
				int d1 = distance(a.begin(),upper_bound(a.begin(),a.end(),a[d0] + (1<<j)));
				d1--;
				int temp = (1<<i) - a[d0];
				temp += (1<<j) - (a[d1]-a[d0]);
				int remain = n - a[d1];
				rep(k,20){
					if((1<<k)>=remain){
						temp += (1<<k) - remain;
						break;
					}
				}
				ans= min(ans,temp);
				
			}
		}
		printf("%d\n",ans);
		
	}
	
	return 0;
}