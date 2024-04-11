#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

void ng(){
	cout<<"NO"<<endl;
}

int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		vector<pair<int,pair<int,int>>> d(3);
		rep(i,3){
			cin>>d[i].first;
			d[i].second = make_pair(i,(i+1)%3);
		}
		sort(d.begin(),d.end());
		if((d[0].first+d[1].first+d[2].first)%2==1){
			ng();
			continue;
		}
		if(d[2].first > d[0].first + d[1].first){
			ng();
			continue;
		}
		vector<int> a,b;
		int c = 3;
		int x,y,z;
		y = d[2].second.first ^ d[2].second.second ^ 3;
		x = d[0].second.first ^ d[0].second.second ^ y;
		z = d[1].second.first ^ d[1].second.second ^ y;
		if(d[0].first + d[1].first == d[2].first){
			int tt = x;
			rep(i,d[0].first-1){
				a.push_back(tt);
				b.push_back(c);
				tt = c;
				c++;
			}
			a.push_back(tt);
			b.push_back(y);
			
			tt = z;
			rep(i,d[1].first-1){
				a.push_back(tt);
				b.push_back(c);
				tt = c;
				c++;
			}
			a.push_back(tt);
			b.push_back(y);
			
		}
		else{
			int tt = x;
			rep(i,d[2].first-1){
				a.push_back(tt);
				b.push_back(c);
				tt = c;
				c++;
			}
			a.push_back(tt);
			b.push_back(z);
			int diff = d[0].first + d[1].first - d[2].first;
			diff/=2;
			tt = x;
			rep(i,d[0].first - diff){
				if(tt==x)tt = 3;
				else tt++;
			}
			if(tt>=c)tt = z;
			rep(i,diff-1){
				a.push_back(tt);
				b.push_back(c);
				tt = c;
				c++;
			}
			a.push_back(tt);
			b.push_back(y);
		}
		//cout<<c<<endl;
		if(c>n){
			ng();
			continue;
		}
		while(c!=n){
			a.push_back(c-1);
			b.push_back(c);
			c++;
		}
		cout<<"YES"<<endl;
		rep(i,n-1){
			printf("%d %d\n",a[i]+1,b[i]+1);
		}
	}
	
    return 0;
}