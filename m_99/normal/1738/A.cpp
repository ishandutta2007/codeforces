#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<long long> a(n),b(n);
		rep(i,n)scanf("%lld",&a[i]);
		rep(i,n)scanf("%lld",&b[i]);
		int c0 = 0,c1 = 0;
		rep(i,n){
			if(a[i]==0)c0++;
			else c1++;
		}
		
		long long ans = 0;
		rep(i,2){
			string s = "";
			int x = c0,y = c1;
			while(x!=0||y!=0){
				if(y==0){
					s += '0';
					x--;
				}
				else if(x==0){
					s += '1';
					y --;
				}
				else{
					if(s.size()%2==i){
						s += '0';
						x--;
					}
					else{
						s += '1';
						y--;
					}
					
				}
				
			}
			vector<vector<long long>> bs(2),ms(2);
			rep(i,n){
				bs[a[i]].push_back(b[i]);
			}
			rep(i,n){
				if(i==0 || s[i]==s[i-1]){
					ms[s[i]-'0'].push_back(1);
				}
				else{
					ms[s[i]-'0'].push_back(2);
				}
			}
			long long sum = 0;
			rep(i,2){
				sort(bs[i].begin(),bs[i].end());
				sort(ms[i].begin(),ms[i].end());
				rep(j,bs[i].size())sum += ms[i][j] * bs[i][j];
			}
			ans = max(ans,sum);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}