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
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	int p=0;
	int f=-1;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]=='.') p=1;
		else {
			if (p==1&&(s[i]-'0')>=5){
				f=i;
				break;
			}
		}
	}
	if (f==-1){
		cout<<s<<endl;
		return 0;
	}
	string ss;
	for (int i=0;i<=f;i++){
		ss+=s[i];
	}
	n=ss.size();
	while((ss.back()-'0')>=5&&t>0){
		if (ss[n-2]=='.'){
			if (ss[n-3]=='9'){
				ss.pop_back();
				ss.pop_back();
				n-=3;
				while (ss[n]=='9'){
					ss[n]='0';
					n--;
					if (n==-1){
						ss='1'+ss;
						break;
					}
				}
				if (n>=0) ss[n]++;
				cout<<ss<<endl;
				return 0;
			}
			else{
				ss[n-3]++;
				ss.pop_back();
				ss.pop_back();
				cout<<ss<<endl;
				return 0;
			}
		}
		else{
			ss[n-2]++;
			ss.pop_back();
			n--;
			t--;
		}
	}
	cout<<ss<<endl;
}