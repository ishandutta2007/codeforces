#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

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

	int n;
	cin>>n;
	
	vector<int> p(n);
	vector<int> pos(n);
	for(int i=0;i<n;i++){
		cin>>p[i];
		pos[p[i]-1] = i;
	}
	
	int maxi = 1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(pos[j-1]>pos[j]){
				i = j-1;
				break;
			}
			maxi = max(maxi,j-i+1);
			if(j==n-1){
				i = n;
			}
		}
	}
	
	cout<<n-maxi<<endl;

	return 0;
}