#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	string l,r;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]=='0'&&l.size()==0) continue;
		if (s[i]=='.') break;
		l+=s[i];
	}
	int pf=0;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]=='.'){
			pf=1;
		}
		else if(pf==1){
			r+=s[i];
		}
	}
	while (r.size()>0&&r.back()=='0') r.pop_back();
	if (l.size()==0&&r.size()==0){
		cout<<0<<endl;
		return 0;
	}
	if (l.size()==0){
		int skz=0;
		string rr;
		for (int i=0;i<(int)r.size();i++){
			if (r[i]=='0'&&rr.size()==0) {
				skz++;
				continue;
			}
			rr+=r[i];
		}
		cout<<rr[0];
		if (rr.size()>1){
			cout<<".";
			for (int i=1;i<(int)rr.size();i++){
				cout<<rr[i];
			}
		}
		cout<<"E-"<<skz+1<<endl;
	}
	else {
		int ep=l.size()-1;
		if (r.size()==0){
			while (l.back()=='0') {
				l.pop_back();
			}
		}
		cout<<l[0];
		if (l.size()>1||r.size()>0){
			cout<<".";
			for (int i=1;i<(int)l.size();i++){
				cout<<l[i];
			}
			for (int i=0;i<(int)r.size();i++){
				cout<<r[i];
			}
		}
		if (ep!=0){
			cout<<"E"<<ep;
		}
		cout<<endl;
	}
}