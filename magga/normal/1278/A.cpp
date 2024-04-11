#include<bits/stdc++.h>
using namespace std;
void solve(){
	map<char,int>m;
	map<char,int>st;
	string p,h;
	cin>>p;
	cin>>h;
	if(p.size()>h.size()){
		cout<<"NO"<<"\n";
		return;
	}
	for(char c:p){
		st[c]++;
	}
	for(int i=0;i<p.size();i++){
		m[h[i]]++;
	}
	if(m==st){
		cout<<"YES"<<"\n";
		return;
	}
	for(int i=p.size();i<h.size();i++){
		m[h[i]]++;
		m[h[i-p.size()]]--;
		if(m[h[i-p.size()]]==0){
			m.erase(h[i-p.size()]);
		}
		if(m==st){
			cout<<"YES"<<"\n";
			return;
		}
	}
	cout<<"NO"<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1 ;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }
}