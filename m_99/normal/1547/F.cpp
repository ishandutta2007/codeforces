#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

template <typename T,typename F>
struct SWAG{
	F func;
	T init_value;
	vector<pair<T,T>> X,Y;
	SWAG(F f,T iv):func(f){
		init_value = iv;
	}
	
	void push_front(T x){
		if(X.empty())X.push_back({x,x});
		else X.push_back({x,func(x,X.back().second)});
	}
	
	void push_back(T x){
		if(Y.empty())Y.push_back({x,x});
		else Y.push_back({x,func(Y.back().second,x)});
	}
	
	void pop_front(){
		if(X.empty()){
			int n = Y.size();
			vector<T> t;
			for(int i=0;i<n/2;i++){
				t.push_back(Y.back().first);
				Y.pop_back();
			}
			while(!Y.empty()){
				push_front(Y.back().first);
				Y.pop_back();
			}
			while(!t.empty()){
				push_back(t.back());
				t.pop_back();
			}
			if(!X.empty())X.pop_back();
		}
		else{
			X.pop_back();
		}
	}
	
	void pop_back(){
		if(Y.empty()){
			int n = X.size();
			stack<T> t;
			for(int i=0;i<n/2;i++){
				t.push_back(X.back().first);
				X.pop_back();
			}
			while(!X.empty()){
				push_back(X.back().first);
				X.pop_back();
			}
			while(!t.empty()){
				push_front(t.back());
				t.pop_back();
			}
			if(!Y.empty())Y.pop_back();
		}
		else{
			Y.pop_back();
		}
	}
	
	T get(){
		T ret = init_value;
		if(!X.empty())ret = func(ret,X.back().second);
		if(!Y.empty())ret = func(ret,Y.back().second);
		return ret;
	}
	
	T front(){
		if(!X.empty())return X.back().first;
		if(!Y.empty())return Y[0].first;
		return init_value;
	}
	
	T back(){
		if(!Y.empty())return Y.back().first;
		if(!X.empty())return X[0].first;
		return init_value;
	}
	
	int size(){
		return X.size()+Y.size();
	}
	
};

int main(){
	
	int _t;
	cin>>_t;
	
	auto f = [](int a,int b){
		return gcd(a,b);
	};
	
	rep(_,_t){
		
		int n;
		scanf("%d",&n);
		
		vector<int> a(n);
		int g = 0;
		rep(i,n){
			scanf("%d",&a[i]);
			g = gcd(g,a[i]);
		}
		
		rep(i,n){
			a.push_back(a[i]);
		}
		
		int ans = 0;
		int r = 1;
		SWAG<int,decltype(f)> S(f,0);
		S.push_back(a[0]);
		rep(i,n){
			while(S.get()!=g){
				S.push_back(a[r]);
				r++;
			}
			ans = max(ans,r-i-1);
			S.pop_front();
		}
		
		printf("%d\n",ans);
		
	}
	
	return 0;
}