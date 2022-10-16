//By MagicSpark
/*
Problem:
Main Idea:
Status:
*/
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
string s;
char get(int pos){
	set<char>can;
	can.insert('B');can.insert('G');can.insert('R');
	if(pos!=0){
		if(can.count(s[pos-1]))can.erase(s[pos-1]);
	}
	if(pos!=s.size()-1){
		if(can.count(s[pos+1]))can.erase(s[pos+1]);
	}
	return *can.begin();
}
bool cmp(int x,int y){
	return (x&1)+(y&1)==1;
}
int main(){
	int n;cin>>n;n=0;
	cin>>s;
	for(int i=0;i<s.size()-1;){
		int pos=i;
		while(pos<s.size()-1&&s[pos]==s[pos+1])pos++;
		n+=(pos-i+1)/2;
		for(int j=i;j<=pos;j++)if(cmp(j,i))s[j]=get(j);
		i=pos+1;
	}
	cout<<n<<endl;
	cout<<s<<endl;
	return 0;
}