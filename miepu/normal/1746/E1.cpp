#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

using vi = basic_string<int>;
int ask(vi S){
	cout<<"? "<<S.size()<<' ';
	for(auto x:S)cout<<x<<' ';
	cout<<endl; 
	string s;cin>>s;
	if(s=="YES")return 1;
	return 0;
}

int res(int k){
	cout<<"! "<<k<<endl;
	string s;cin>>s;
	return s==":)";
}

void solve(){
	int n;cin>>n;
	vi A;A.resize(n);
	for(int i=0;i<n;i++){
		A[i]=i+1;
	}
	while(A.size()>=4){
		vi a,b,c,d;
		int k=A.size()/4;
		for(int i=0;i<k;i++)a.push_back(A[i]);
		for(int i=k;i<2*k;i++)b.push_back(A[i]);
		for(int i=2*k;i<3*k;i++)c.push_back(A[i]);
		for(int i=3*k;i<A.size();i++)d.push_back(A[i]);
		int fl1=ask(a+b),fl2=ask(a+c);
		if(fl1==1&&fl2==1)A=a+b+c;
		if(fl1==1&&fl2==0)A=a+b+d;
		if(fl1==0&&fl2==1)A=a+c+d;
		if(fl1==0&&fl2==0)A=b+c+d;
	}
	if(A.size()==1){
		res(A[0]);
		exit(0);
	}
	if(A.size()==3){
		int fl1=ask({A[0]});
		if(fl1){
			if(ask({A[1]})){
				A={A[0],A[1]};
			}else{
				A={A[0],A[2]};
			}
		}else{
			if(ask({A[0]})){
				if(ask({A[1]})){
					A={A[0],A[1]};
				}else{
					A={A[0],A[2]};
				}
			}else{
				A={A[1],A[2]};
			}
		}
	}
	if(!res(A[0]))res(A[1]);
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;// cin>>_T;
	while(_T--)solve();
}