#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	long long n,m,k;
	cin>>n>>m>>k;
	
	map<int,set<int>> mpx,mpy;
	
	for(int i=0;i<k;i++){
		int x,y;
		cin>>x>>y;
		
		mpx[x].insert(y);
		mpy[y].insert(x);
	}
	
	int x = 1;
	int y = 1;
	int l = 0,r=m+1,u=1,d=n+1;
	int dir = 0;
	long long sum = 1;
	
	for(int i=0;i<300000;i++){
		if(dir==0){
			if(mpx.count(x)){
				auto it = mpx[x].lower_bound(y+1);
				if(it==mpx[x].end())goto L1;
				int a = *it;
				a--;
				if(a>=r)goto L1;
				if(a==y)break;
				sum+=a-y;
				y=a;
				
			}
			else{
				L1:
				r--;
				if(r==y)break;
				sum+=r-y;
				y=r;
			}
			r=y;
			dir++;
		}
		else if(dir==1){
			if(mpy.count(y)){
				auto it = mpy[y].lower_bound(x+1);
				if(it==mpy[y].end())goto L2;
				int a = *it;
				a--;
				if(a>=d)goto L2;
				if(a==x)break;
				sum+=a-x;
				x=a;
			}
			else{
				L2:
				d--;
				if(d==x)break;
				sum+=d-x;
				x=d;
			}
			d=x;
			dir++;
		}
		else if(dir==2){
			if(mpx.count(x)){
				auto it = mpx[x].lower_bound(y);
				if(it==mpx[x].begin())goto L3;
				it--;
				int a = *it;
				a++;
				if(a<=l)goto L3;
				if(a==y)break;
				sum+=y-a;
				y=a;
				
			}
			else{
				L3:
				l++;
				if(l==y)break;
				sum+=y-l;
				y=l;
			}
			l=y;
			dir++;
		}
		else{
			if(mpy.count(y)){
				auto it = mpy[y].lower_bound(x);
				if(it==mpy[y].begin())goto L4;
				it--;
				int a = *it;
				a++;
				if(a<=u)goto L4;
				if(a==x)break;
				sum+=x-a;
				x=a;
			}
			else{
				L4:
				u++;
				if(u==x)break;
				sum+=x-u;
				x=u;
			}
			u=x;
			dir=0;
		}
		//cout<<x<<','<<y<<endl;
	}
	
	
	if(n*m==sum+k){
		cout<<"Yes"<<endl;
		return 0;
	}
	
	x=1,y=1;
	sum=1;
	d=n+1;
	if(mpy.count(y)){
		auto it = mpy[y].lower_bound(x+1);
		if(it==mpy[y].end())goto L5;
		int a = *it;
		a--;
		sum+=a-x;
		x=a;
	}
	else{
		L5:
		d--;
		sum+=d-x;
		x=d;
	}
	
	if(n*m==sum+k){
		cout<<"Yes"<<endl;
		return 0;
	}
	
	cout<<"No"<<endl;

	
	
    return 0;
}