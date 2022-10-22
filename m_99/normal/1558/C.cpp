#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

vector<int> ans;
vector<int> NG = {-1};
void go(vector<int> &a,int x,int y){
	int n = a.size();
	//cout<<n<<endl;
	bool f = false;
	for(int i=1;i<=n;i+=2){
		if(a[i-1]==y){
			ans.push_back(i);
			f = true;
			reverse(a.begin(),a.begin()+i);
			//cout<<i<<endl;
			break;
		}
	}
	if(!f){
		ans = NG;
		return;
	}
	f = false;
	for(int i=2;i<=n;i+=2){
		if(a[i-1]==x){
			ans.push_back(i-1);
			reverse(a.begin(),a.begin()+i-1);
			f = true;
			break;
		}
	}
	if(!f){
		ans = NG;
		return;
	}
	
	for(int i=2;i<=n;i+=2){
		if(a[i-1]==x){
			ans.push_back(i+1);
			reverse(a.begin(),a.begin()+1+i);
			break;
		}
	}
	
	reverse(a.begin(),a.begin()+3);
	ans.push_back(3);
	reverse(a.begin(),a.end());
	ans.push_back(a.size());
	return;
	
}

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		ans.resize(0);
		bool f = true;
		for(int i=n;i!=1;i-=2){
			go(a,i-1,i);
			if(ans==NG){
				f = false;
				break;
			}
			rep(j,2)a.pop_back();
		}
		
		if(!f){
			cout<<-1<<endl;
		}
		else{
			cout<<ans.size()<<endl;
			rep(j,ans.size()){
				if(j!=0)cout<<' ';
				cout<<ans[j];
			}
			cout<<endl;
		}
	}
		
	
	return 0;
}