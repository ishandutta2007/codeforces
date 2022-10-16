#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

string s;
int n;

vector<int> calc(int i){
	int st=s[i]=='A';
	for(int j=i+1;j<=n;j++){
		if(j==n||s[j]==s[j-1]){
			int l=j-i;
			if(l&1)return {j,l/2,0,0};
			else return {j,0,l/2*st,l/2*!st};
		}
	}
}

void solve(){
	int a,b,c,d;cin>>a>>b>>c>>d;
	cin>>s;n=s.size();
	int _a=count(s.begin(),s.end(),'A');
	int _b=count(s.begin(),s.end(),'B');
	if(_a!=a+c+d||_b!=b+c+d){
		cout<<"NO"<<endl;
		return;
	}
	int t=0,C=0;basic_string <int> ty0,ty1;
	while(t!=n){
		auto x=calc(t);
		t=x[0],C+=x[1],ty0+=x[2],ty1+=x[3];
	}
	auto s1=accumulate(ty0.begin(),ty0.end(),0);
	auto s2=accumulate(ty1.begin(),ty1.end(),0);
	sort(ty0.begin(),ty0.end());
	sort(ty1.begin(),ty1.end());
	if(c+d>C+s1+s2){
		cout<<"NO"<<endl;
		return ;
	}
	while(c>C+s1||d>C+s2){
		if(d>C+s2){
			if(ty0.empty()){
				cout<<"NO"<<endl;
				return ;
			}
			s1-=ty0.back();
			s2+=ty0.back()-1;
			ty0.pop_back();
			if(c+d>C+s1+s2){
				cout<<"NO"<<endl;
				return ;
			}
			if(d<=C+s2){
				cout<<"YES"<<endl;
				return ;
			}
		}else{
			if(ty1.empty()){
				cout<<"NO"<<endl;
				return ;
			}
			s1+=ty1.back()-1;
			s2-=ty1.back();
			ty1.pop_back();
			if(c+d>C+s1+s2){
				cout<<"NO"<<endl;
				return ;
			}
			if(c<=C+s1){
				cout<<"YES"<<endl;
				return ;
			}
		}
	}
	cout<<"YES"<<endl; 
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}