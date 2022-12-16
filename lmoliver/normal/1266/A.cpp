#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(S);N<=(int)(E);N++)

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int s3=0;
		bool h0=false;
		int ce=0;
		bool az=true;
		F(i,0,s.size()-1){
			int x=s[i]^'0';
			s3+=x;
			h0|=x==0;
			if(x%2==0)ce++;
			az&=x==0;
		}
		bool ans=az||(s3%3==0&&ce>1&&h0);
		cout<<(ans?"red":"cyan")<<endl;
	}
	return 0;
}