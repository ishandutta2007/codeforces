#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		int M = 1;
		rep(i,n){
			map<pair<int,int>,int> mp;
			rep(j,n){
				if(i==j)continue;
				int x = i-j;
				int y = a[i]-a[j];
				int g = gcd(abs(x),abs(y));
				x /= g;
				y /= g;
				if(x<0){
					x *= -1;
					y *= -1;
				}
				else if(x==0&&y<0){
					y *= -1;
				}
				mp[make_pair(x,y)]++;
					
			}
			for(auto b:mp){
				M = max(M,1+b.second);
			}
		}
		cout<<n-M<<endl;
	}
	
	return 0;
}