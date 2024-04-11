#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin>>n>>s;
	int l1=0;
	int l2=0;
	int p=0;
	int w=0;
	for (int i=0;i<n;i++){
		if (s[i]=='_') {
			if (w>0&&p){
				l2++;
			}
			w=0;
		}
		else if(s[i]=='('){
			w=0;
			p=1;
		}
		else if(s[i]==')'){
			if (w>0) l2++;
			p=0;
			w=0;
		}
		else {
			w++;
			if (!p) l1=max(l1, w);
		}
	}
	cout<<l1<<" "<<l2<<endl;
}