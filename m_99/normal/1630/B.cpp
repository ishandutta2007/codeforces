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
		vector<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		int ok;
		rep(i,1000000){
			int x = i;
			int y = n-i;
			if(x - y >= k){
				ok = i;
				break;
			}
		}
		auto b = a;
		sort(a.begin(),a.end());
		int x = 0;
		rep(i,n){
			int temp = -a[i];
			if(i+ok-1>=n)break;
			temp += a[i+ok-1];
			if(a[x+ok-1] - a[x] > temp){
				x = i;
			}
		}
		printf("%d %d\n",a[x],a[x+ok-1]);
		int y = a[x+ok-1];
		x = a[x];
		
		a = b;
		vector<int> l,r;
		int s = 0;
		int ll = 0;
		
		rep(i,n){
			//cout<<a[i]<<','<<x<<','<<y<<endl;
			if(a[i]>=x&&a[i]<=y)s++;
			else s--;
			if(s>0){
				l.push_back(ll);
				r.push_back(i);
				ll = i+1;
				s = 0;
				continue;
			}
		}
	//	cout<<l.size()<<endl;
		//if(ll!=n)r.back() = n-1;
		while(l.size()!=k){
			l.pop_back();
			r.pop_back();
		}
		r.back() = n-1;
		rep(i,k){
			printf("%d %d\n",l[i]+1,r[i]+1);
		}
	}
	
	return 0;
}