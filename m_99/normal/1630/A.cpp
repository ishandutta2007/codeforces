#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,k;
		scanf("%d %d",&n,&k);
		if(k==n-1&&n==4){
			cout<<-1<<endl;
		}
		else{
			int l = 0,r = n-1;
			vector<int> a,b;
			while(l <= r){
				a.push_back(l);
				b.push_back(r);
				l++;
				r--;
			}
			if(k!=n-1){
				rep(i,a.size()){
					if(a[i]==k){
						swap(a[i],a[0]);
						break;
					}
					if(b[i]==k){
						swap(b[i],a[0]);
						break;
					}
				}
			}
			else{
				a[0] = 0;
				b[0] = n-4;
				a[1] = 1;
				a[2] = 2;
				a[3] = n-2;
				b[1] = 3;
				b[2] = n-3;
				b[3] = n-1;
				
			}
			int ans = 0;
			rep(i,a.size()){
				ans += a[i] & b[i];
			}
			//cout<<k<<','<<ans<<endl;
			rep(i,a.size()){
				printf("%d %d\n",a[i],b[i]);
			}
				
			
			
		}
		
	}
	
	return 0;
}