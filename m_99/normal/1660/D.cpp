#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001

pair<pair<int,int>,int> get(vector<int> t){
	
	int c = 0,b = 0;
	rep(i,t.size()){
		if(t[i]<0)b^=1;
		if(abs(t[i])==2)c++;
	}
	if(b==0)return make_pair(make_pair(0,0),c);
	int x=0,y=0;
	int c0 = 0,c1 = 0;
	{
		int cc = c;
		auto tt = t;
		
		while(true){
			if(abs(tt.back())==2)cc--;
			y++;
			if(tt.back()<0)break;
			tt.pop_back();
		}
		c1 = cc;
	}
	{
		int cc = c;
		auto tt = t;
		reverse(tt.begin(),tt.end());
		while(true){
			if(abs(tt.back())==2)cc--;
			x++;
			if(tt.back()<0)break;
			tt.pop_back();
		}
		c0 = cc;
	}
	if(c0>c1)return make_pair(make_pair(x,0),c0);
	else return make_pair(make_pair(0,y),c1);
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		deque<int> a(n);
		rep(i,n)scanf("%d",&a[i]);
		int x = 0,y = n,m=  0;
		while(a.size()!=0){
			int xx = n - a.size();
			int yy = 0;
			vector<int> t;
			while(a.size()>0 && a.front()!=0){
				t.push_back(a.front());
				a.pop_front();
			}
			yy = a.size();
			if(a.size()>0)a.pop_front();
		
			auto ret  = get(t);
			
			xx += ret.first.first;
			yy += ret.first.second;
			if(m<ret.second){
				m = ret.second;
				x = xx,y = yy;
			}
		}
		cout<<x<<' '<<y<<endl;
		
	}
	
	return 0;
}