#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int get(pair<int,int> p0,pair<int,int> p1){
	//swap(p0,p1);
	return p0.second + p1.first;
}

vector<long long> get(int s,int a,int b){
	int A = (s+1)/2;
	int B = s-A;
	
	pair<int,int> p0(0,0),p1(0,0);
	while(p0.first+p0.second<A&&a>0){
		a--;
		p0.first++;
	}
	while(p1.first+p1.second<B&&b>0){
		b--;
		p1.second++;
	}
	while(p0.first+p0.second<A&&b>0){
		b--;
		p0.second++;
	}
	while(p1.first+p1.second<B&&a>0){
		a--;
		p1.first++;
	}
//cout<<p0.first<<','<<p0.second<<','<<p1.first<<','<<p1.second<<endl;
	vector<long long> ret(1,get(p0,p1));

	//if(p0.second>0){
		while(p0.first>0&&p1.second>0){
			
			p0.second++;
			p0.first--;
			p1.second--;
			p1.first++;
		//	cout<<p0.first<<','<<p0.second<<','<<p1.first<<','<<p1.second<<endl;
			ret.push_back(get(p0,p1));
			
		}
	//}
	//else if(p1.first>0){
		while(p1.second>0&&p0.first>0){
			p0.second++;
			p0.first--;
			p1.second--;
			p1.first++;
			//cout<<p0.first<<','<<p0.second<<','<<p1.first<<','<<p1.second<<endl;
			ret.push_back(get(p0,p1));
		}
	//}
	return ret;
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long a,b;
		cin>>a>>b;
		
		long long s = a+b;
		
		vector<long long> t0 = get(s,a,b);
		vector<long long> t1 = get(s,b,a);
		rep(i,t1.size())t0.push_back(t1[i]);
		sort(t0.begin(),t0.end());
		t0.erase(unique(t0.begin(),t0.end()),t0.end());
		cout<<t0.size()<<endl;
		rep(i,t0.size()){
			if(i!=0)cout<<' ';
			cout<<t0[i];
		}
		cout<<endl;
		
		
		
	}
	
	return 0;
}