#include<bits/stdc++.h>
#pragma comment(linker, "/STACK:16000000")
#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
string s[111];
inline string getstr(string s,int l,int r){
	string re="";
	for(int i=l;i<=r;i++)re.push_back(s[i]);
	return re;
}
bool cmp(string a,string b){
	return a.size()<b.size();
}
bool ok(string a,string b){
	for(int i=0;i<b.size();i++){
		if(i+a.size()>b.size())break;
		if(getstr(b,i,i+a.size()-1)==a)return true;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<n-1;i++)if(!ok(s[i],s[i+1])){
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=0;i<n;i++)cout<<s[i]<<endl;
	#ifndef ONLINE_JUDGE
		printf("-----\n");
        printf("Time: %d ms\n", (int)(clock() * 1000/ CLOCKS_PER_SEC));
    #endif
	return 0;
}